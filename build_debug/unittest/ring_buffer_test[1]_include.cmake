if(EXISTS "/root/miniob2/Miniob-Solution-2023-main/build_debug/unittest/ring_buffer_test[1]_tests.cmake")
  include("/root/miniob2/Miniob-Solution-2023-main/build_debug/unittest/ring_buffer_test[1]_tests.cmake")
else()
  add_test(ring_buffer_test_NOT_BUILT ring_buffer_test_NOT_BUILT)
endif()