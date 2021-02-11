cmake_minimum_required(VERSION 3.0.0)
project(Singleton VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Singleton 
                Client.cpp
                Singleton.cpp
                Singleton.hpp
            )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(NOT WIN32 AND NOT APPLE)
    find_package(Threads REQUIRED)
    target_link_libraries(Singleton PRIVATE Threads::Threads)
endif()
