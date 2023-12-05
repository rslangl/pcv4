include(CMakeFindDependencyMacro)
find_dependency(fmt)

include("${CMAKE_CURRENT_LIST_DIR}/elastic_task_queueTargets.cmake")
