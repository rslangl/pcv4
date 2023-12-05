if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/elastic_task_queue-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package elastic_task_queue)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT elastic_task_queue_Development
)

install(
    TARGETS elastic_task_queue_elastic_task_queue
    EXPORT elastic_task_queueTargets
    RUNTIME #
    COMPONENT elastic_task_queue_Runtime
    LIBRARY #
    COMPONENT elastic_task_queue_Runtime
    NAMELINK_COMPONENT elastic_task_queue_Development
    ARCHIVE #
    COMPONENT elastic_task_queue_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    elastic_task_queue_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE elastic_task_queue_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(elastic_task_queue_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${elastic_task_queue_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT elastic_task_queue_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${elastic_task_queue_INSTALL_CMAKEDIR}"
    COMPONENT elastic_task_queue_Development
)

install(
    EXPORT elastic_task_queueTargets
    NAMESPACE elastic_task_queue::
    DESTINATION "${elastic_task_queue_INSTALL_CMAKEDIR}"
    COMPONENT elastic_task_queue_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
