add_test( test_bplus_tree.test_leaf_index_node_handle /root/miniob2/Miniob-Solution-2023-main/build_debug/bin/bplus_tree_test [==[--gtest_filter=test_bplus_tree.test_leaf_index_node_handle]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bplus_tree.test_leaf_index_node_handle PROPERTIES WORKING_DIRECTORY /root/miniob2/Miniob-Solution-2023-main/build_debug/unittest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( test_bplus_tree.test_internal_index_node_handle /root/miniob2/Miniob-Solution-2023-main/build_debug/bin/bplus_tree_test [==[--gtest_filter=test_bplus_tree.test_internal_index_node_handle]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bplus_tree.test_internal_index_node_handle PROPERTIES WORKING_DIRECTORY /root/miniob2/Miniob-Solution-2023-main/build_debug/unittest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( test_bplus_tree.test_chars /root/miniob2/Miniob-Solution-2023-main/build_debug/bin/bplus_tree_test [==[--gtest_filter=test_bplus_tree.test_chars]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bplus_tree.test_chars PROPERTIES WORKING_DIRECTORY /root/miniob2/Miniob-Solution-2023-main/build_debug/unittest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( test_bplus_tree.test_scanner /root/miniob2/Miniob-Solution-2023-main/build_debug/bin/bplus_tree_test [==[--gtest_filter=test_bplus_tree.test_scanner]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bplus_tree.test_scanner PROPERTIES WORKING_DIRECTORY /root/miniob2/Miniob-Solution-2023-main/build_debug/unittest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( test_bplus_tree.test_bplus_tree_insert /root/miniob2/Miniob-Solution-2023-main/build_debug/bin/bplus_tree_test [==[--gtest_filter=test_bplus_tree.test_bplus_tree_insert]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bplus_tree.test_bplus_tree_insert PROPERTIES WORKING_DIRECTORY /root/miniob2/Miniob-Solution-2023-main/build_debug/unittest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( bplus_tree_test_TESTS test_bplus_tree.test_leaf_index_node_handle test_bplus_tree.test_internal_index_node_handle test_bplus_tree.test_chars test_bplus_tree.test_scanner test_bplus_tree.test_bplus_tree_insert)