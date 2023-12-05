# ---- Developer mode ----

# Developer mode enables targets and code paths in the CMake scripts that are
# only relevant for the developer(s) of elastic_task_queue
# Targets necessary to build the project must be provided unconditionally, so
# consumers can trivially build and package the project
if(PROJECT_IS_TOP_LEVEL)
  option(elastic_task_queue_DEVELOPER_MODE "Enable developer mode" OFF)
  option(BUILD_SHARED_LIBS "Build shared libs." OFF)
endif()

# ---- Suppress C4251 on Windows ----

# Please see include/elastic_task_queue/elastic_task_queue.hpp for more details
set(pragma_suppress_c4251 "
/* This needs to suppress only for MSVC */
#if defined(_MSC_VER) && !defined(__ICL)
#  define ELASTIC_TASK_QUEUE_SUPPRESS_C4251 _Pragma(\"warning(suppress:4251)\")
#else
#  define ELASTIC_TASK_QUEUE_SUPPRESS_C4251
#endif
")

# ---- Warning guard ----

# target_include_directories with the SYSTEM modifier will request the compiler
# to omit warnings from the provided paths, if the compiler supports that
# This is to provide a user experience similar to find_package when
# add_subdirectory or FetchContent is used to consume this project
set(warning_guard "")
if(NOT PROJECT_IS_TOP_LEVEL)
  option(
      elastic_task_queue_INCLUDES_WITH_SYSTEM
      "Use SYSTEM modifier for elastic_task_queue's includes, disabling warnings"
      ON
  )
  mark_as_advanced(elastic_task_queue_INCLUDES_WITH_SYSTEM)
  if(elastic_task_queue_INCLUDES_WITH_SYSTEM)
    set(warning_guard SYSTEM)
  endif()
endif()
