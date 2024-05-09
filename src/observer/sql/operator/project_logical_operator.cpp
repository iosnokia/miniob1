/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/12/15
//

#include "sql/operator/project_logical_operator.h"

ProjectLogicalOperator::ProjectLogicalOperator(std::vector<std::unique_ptr<Expression>> exprs)
{
  for (auto &expr : exprs) {
    expressions_.push_back(std::move(expr));
  }
}
std::vector<std::unique_ptr<Expression>> &&ProjectLogicalOperator::take_exprs() { return std::move(expressions_); }