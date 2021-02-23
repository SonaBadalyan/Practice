cmake_minimum_required(VERSION 3.0.0)
project(Visitor VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Visitor Client.cpp
                        Customer.hpp
                        Mary.hpp
                        Bob.hpp
                        Visitor.hpp
                        Grinch.hpp
                        Santa.hpp
                        )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
