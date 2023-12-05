cmake_minimum_required(VERSION 3.14)

project(elastic_task_queueTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(elastic_task_queue REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(elastic_task_queue_test source/elastic_task_queue_test.cpp)
target_link_libraries(
    elastic_task_queue_test PRIVATE
    elastic_task_queue::elastic_task_queue
    Catch2::Catch2WithMain
)
target_compile_features(elastic_task_queue_test PRIVATE cxx_std_20)

catch_discover_tests(elastic_task_queue_test)

# ---- End-of-file commands ----

add_folders(Test)
