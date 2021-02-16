cmake_minimum_required(VERSION 3.0.0)
project(Strategy VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Strategy Client.cpp
                        SortStrategy.hpp
                        SortingContext.hpp
                        SortingContext.cpp
                        BubbleSort.hpp
                        BubbleSort.cpp
                        InsertionSort.hpp
                        InsertionSort.cpp
                        SelectionSort.hpp
                        SelectionSort.cpp
                        )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
