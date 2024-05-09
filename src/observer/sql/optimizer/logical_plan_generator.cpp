/* Copyright (c) 2023 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/08/16.
//

#include "sql/optimizer/logical_plan_generator.h"

#include "sql/operator/logical_operator.h"
#include "sql/operator/calc_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/predicate_logical_operator.h"
#include "sql/operator/table_get_logical_operator.h"
#include "sql/operator/insert_logical_operator.h"
#include "sql/operator/delete_logical_operator.h"
#include "sql/operator/join_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/explain_logical_operator.h"
#include "sql/operator/update_logical_operator.h"
#include "sql/operator/sort_logical_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/calc_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/explain_stmt.h"
#include "sql/operator/aggregate_logical_operator.h"
#include "sql/stmt/update_stmt.h"

using namespace std;

RC LogicalPlanGenerator::create(Stmt *stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  RC rc = RC::SUCCESS;
  switch (stmt->type()) {
    case StmtType::CALC: {
      CalcStmt *calc_stmt = static_cast<CalcStmt *>(stmt);
      rc                  = create_plan(calc_stmt, logical_operator);
    } break;

    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
      rc                      = create_plan(select_stmt, logical_operator);
    } break;

    case StmtType::INSERT: {
      InsertStmt *insert_stmt = static_cast<InsertStmt *>(stmt);
      rc                      = create_plan(insert_stmt, logical_operator);
    } break;

    case StmtType::DELETE: {
      DeleteStmt *delete_stmt = static_cast<DeleteStmt *>(stmt);
      rc                      = create_plan(delete_stmt, logical_operator);
    } break;

    case StmtType::UPDATE: {
      UpdateStmt *update_stmt = static_cast<UpdateStmt *>(stmt);
      rc                      = create_plan(update_stmt, logical_operator);
    } break;

    case StmtType::EXPLAIN: {
      ExplainStmt *explain_stmt = static_cast<ExplainStmt *>(stmt);
      rc                        = create_plan(explain_stmt, logical_operator);
    } break;
    default: {
      rc = RC::UNIMPLENMENT;
    }
  }
  return rc;
}

RC LogicalPlanGenerator::create_plan(CalcStmt *calc_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  logical_operator.reset(new CalcLogicalOperator(std::move(calc_stmt->expressions())));
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(SelectStmt *select_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  unique_ptr<LogicalOperator> table_oper(nullptr);

  const std::vector<Table *> &tables      = select_stmt->tables();
  auto                        query_exprs = select_stmt->take_exprs();
  for (size_t i = 0; i < tables.size(); i++) {
    Table             *table = tables[i];
    std::vector<Field> fields;  // TODO: fields not used
                                //    for (const auto &expr : query_exprs) {
                                //      if (0 == strcmp(expr.table_name(), table->name())) {
                                //        fields.push_back(expr);
                                //      }
                                //    }

    unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, true /*readonly*/));
    if (table_oper == nullptr) {
      table_oper = std::move(table_get_oper);
    } else {
      RC rc;
      if (select_stmt->join_stmts().empty()) {
        JoinLogicalOperator *join_oper = new JoinLogicalOperator;
        join_oper->add_child(std::move(table_oper));
        join_oper->add_child(std::move(table_get_oper));
        table_oper = unique_ptr<LogicalOperator>(join_oper);
      } else {
        unique_ptr<LogicalOperator> join_oper;
        rc = create_plan(select_stmt->join_stmts()[i - 1], join_oper);
        join_oper->add_child(std::move(table_oper));
        join_oper->add_child(std::move(table_get_oper));
        table_oper = std::move(join_oper);
      }

      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to create join logical plan ,rc = %s", strrc(rc));
        return rc;
      }
    }
  }

  unique_ptr<LogicalOperator> aggregate_oper;
  {
    if (!select_stmt->aggregates().empty()) {
      aggregate_oper = std::make_unique<AggregateLogicalOperator>(select_stmt->aggregates(), select_stmt->group_bys());
    }
  }

  unique_ptr<LogicalOperator> predicate_oper;
  RC                          rc = create_plan(select_stmt->filter_stmt(), predicate_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create predicate logical plan. rc=%s", strrc(rc));
    return rc;
  }

  unique_ptr<LogicalOperator> having_oper;
  rc = create_plan(select_stmt->having_stmt(), having_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create having logical plan. rc=%s", strrc(rc));
    return rc;
  }

  unique_ptr<LogicalOperator> project_oper(new ProjectLogicalOperator(std::move(query_exprs)));
  if (predicate_oper) {
    if (table_oper) {
      predicate_oper->add_child(std::move(table_oper));
    }
    table_oper = std::move(predicate_oper);
  }

  if (aggregate_oper) {
    if (table_oper) {
      aggregate_oper->add_child(std::move(table_oper));
    }
    table_oper = std::move(aggregate_oper);
  }

  if (having_oper) {
    if (table_oper) {
      having_oper->add_child(std::move(table_oper));
    }
    table_oper = std::move(having_oper);
  }

  if (project_oper) {
    if (table_oper) {
      project_oper->add_child(std::move(table_oper));
    }
    table_oper = std::move(project_oper);
  }
  unique_ptr<LogicalOperator> sort_oper(new SortLogicalOperator(select_stmt->order_by_elems()));
  if (select_stmt->order_by_elems().size() != 0) {
    if (table_oper) {
      sort_oper->add_child(std::move(table_oper));
    }
    table_oper = std::move(sort_oper);
  }

  logical_operator.swap(table_oper);
  return RC::SUCCESS;
}

ConjunctionExpr *recursive_create_comparison(FilterTree *filter_tree)
{
  if (filter_tree == nullptr) {
    return nullptr;
  }
  if (filter_tree->filter_unit != nullptr) {
    let_ref    filter_unit      = filter_tree->filter_unit;
    FilterObj &filter_obj_left  = filter_unit->left();
    FilterObj &filter_obj_right = filter_unit->right();

    auto left  = std::move(filter_obj_left.expr);
    auto right = std::move(filter_obj_right.expr);

    auto *cmp_expr = new ComparisonExpr(filter_unit->comp(), std::move(left), std::move(right));
    return new ConjunctionExpr(std::unique_ptr<ComparisonExpr>(cmp_expr));
  } else {
    let_mut left    = recursive_create_comparison(filter_tree->left.get());
    let_mut right   = recursive_create_comparison(filter_tree->right.get());
    let_mut p_left  = std::unique_ptr<ConjunctionExpr>(left);
    let_mut p_right = std::unique_ptr<ConjunctionExpr>(right);

    return new ConjunctionExpr(filter_tree->type, std::move(p_left), std::move(p_right));
  }
}

RC LogicalPlanGenerator::create_plan(FilterStmt *filter_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  std::vector<unique_ptr<Expression>> cmp_exprs;
  FilterTree                         *filter_tree = filter_stmt->filter_tree();

  let cmp_expr = recursive_create_comparison(filter_tree);

  unique_ptr<PredicateLogicalOperator> predicate_oper;
  if (cmp_expr != nullptr) {
    let_mut conjunction_expr = std::unique_ptr<ConjunctionExpr>(cmp_expr);
    predicate_oper           = std::make_unique<PredicateLogicalOperator>(std::move(conjunction_expr));
  }

  logical_operator = std::move(predicate_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(JoinStmt *join_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  if (join_stmt == nullptr) {}
  FilterTree                     *filter_tree = join_stmt->filter_tree();
  let                             cmp_expr    = recursive_create_comparison(filter_tree);
  unique_ptr<JoinLogicalOperator> join_oper;
  if (cmp_expr != nullptr) {
    let_mut conjunction_expr = std::unique_ptr<ConjunctionExpr>(cmp_expr);
    join_oper                = std::make_unique<JoinLogicalOperator>(std::move(conjunction_expr));
  }
  logical_operator = std::move(join_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(InsertStmt *insert_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table        *table = insert_stmt->table();
  vector<Value> values(insert_stmt->values(), insert_stmt->values() + insert_stmt->value_amount());

  InsertLogicalOperator *insert_operator = new InsertLogicalOperator(table, values);
  logical_operator.reset(insert_operator);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(DeleteStmt *delete_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table             *table       = delete_stmt->table();
  FilterStmt        *filter_stmt = delete_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, false /*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC                          rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  unique_ptr<LogicalOperator> delete_oper(new DeleteLogicalOperator(table));

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    delete_oper->add_child(std::move(predicate_oper));
  } else {
    delete_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(delete_oper);
  return rc;
}

RC LogicalPlanGenerator::create_plan(UpdateStmt *update_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table             *table       = update_stmt->table();
  FilterStmt        *filter_stmt = update_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields, false /*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC                          rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  // 现在已经拿到了过滤后的数据，需要对每一行的固定数据进行修改
  // 应该新增一个update算子
  // 所以顺序是，先拿table，再过滤，再加入update
  let_mut update_physical_oper = new UpdateLogicalOperator(table, update_stmt->field_and_value());
  update_physical_oper->fragile = update_stmt->fragile;

  unique_ptr<LogicalOperator> update_oper(update_physical_oper);

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    update_oper->add_child(std::move(predicate_oper));
  } else {
    update_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(update_oper);

  return rc;
}

RC LogicalPlanGenerator::create_plan(ExplainStmt *explain_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Stmt                       *child_stmt = explain_stmt->child();
  unique_ptr<LogicalOperator> child_oper;
  RC                          rc = create(child_stmt, child_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create explain's child operator. rc=%s", strrc(rc));
    return rc;
  }

  logical_operator = unique_ptr<LogicalOperator>(new ExplainLogicalOperator);
  logical_operator->add_child(std::move(child_oper));
  return rc;
}
