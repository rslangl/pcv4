cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    elastic_task_queue
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    elastic_task_queue_elastic_task_queue
    source/elastic_task_queue.cpp
    source/producer.cpp
)
add_library(elastic_task_queue::elastic_task_queue ALIAS elastic_task_queue_elastic_task_queue)

include(GenerateExportHeader)
generate_export_header(
    elastic_task_queue_elastic_task_queue
    BASE_NAME elastic_task_queue
    EXPORT_FILE_NAME export/elastic_task_queue/elastic_task_queue_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(elastic_task_queue_elastic_task_queue PUBLIC ELASTIC_TASK_QUEUE_STATIC_DEFINE)
endif()

set_target_properties(
    elastic_task_queue_elastic_task_queue PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME elastic_task_queue
    OUTPUT_NAME elastic_task_queue
)

target_include_directories(
    elastic_task_queue_elastic_task_queue ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    elastic_task_queue_elastic_task_queue SYSTEM
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(elastic_task_queue_elastic_task_queue PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(elastic_task_queue_elastic_task_queue PRIVATE fmt::fmt)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT elastic_task_queue_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of elastic_task_queue"
  )
endif()

include(cmake/dev-mode.cmake)
