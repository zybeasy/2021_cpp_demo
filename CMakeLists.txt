cmake_minimum_required(VERSION 3.0.0)
project(2021_CPP_DEMO VERSION 0.1.0)

include(CTest)
enable_testing()

message(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB TREE_SRC_LIST "tree/*.cpp")
message("TREE_SRC_LIST "${TREE_SRC_LIST})

file(GLOB MAIN_TREE_TEST "tree_test.cpp")
message("MAIN_TREE_TEST "${MAIN_TREE_TEST})

file(GLOB SORT_SRC_LIST "sort/*.cpp")
message("SORT_SRC_LIST "${SORT_SRC_LIST})

file(GLOB MAIN_TEST "test.cpp")
message("MAIN_TEST "${MAIN_TEST})


add_executable(2021_CPP_DEMO main.cpp 
    ${TREE_SRC_LIST} ${MAIN_TREE_TEST} 
    ${SORT_SRC_LIST} ${MAIN_TEST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
