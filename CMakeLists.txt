cmake_minimum_required(VERSION 3.2)
project(P3 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIST_SOURCE
  dynamic_array_list.hpp
  dynamic_array_list.tpp
  linked_list.hpp
  linked_list.tpp)

set(TEST_SOURCE
  test_list.cpp)

set(TODO_SOURCE main.cpp todo.hpp todo.cpp)

set(SOURCE ${LIST_SOURCE} ${TEST_SOURCE} ${TODO_SOURCE})

# create unittests
add_executable(student-tests catch.hpp   abstract_list.hpp ${LIST_SOURCE} ${TEST_SOURCE})

# todo executable
add_executable(todo ${TODO_SOURCE} abstract_list.hpp ${LIST_SOURCE})

enable_testing()

# unit tests
add_test(student-tests student-tests)

# some basic todo tests
add_test(todo01 todo add start HW 0)
add_test(todo02 todo add "read first chapter for class")
add_test(todo03 todo add "ask about templates during office hours")
add_test(todo04 todo list)
add_test(todo05 todo do 2)
add_test(todo06 todo list)
add_test(todo07 todo do 10)

set_tests_properties(todo07 PROPERTIES WILL_FAIL true )

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
