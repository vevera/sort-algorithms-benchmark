cmake_minimum_required(VERSION 3.7)
project(sort_algorithms VERSION 0.1.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)  # Set the default build type to Release if not specified
endif()

set(  
      INCLUDE_FILES
      pivot.hpp
      myrandomgen.hpp
      instances.hpp
      runtime.hpp
      sort_algorithms.hpp
    )

add_executable(sort_algorithms 
                ${INCLUDE_FILES}
                main.cpp
                )

set_target_properties( sort_algorithms PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/" )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)