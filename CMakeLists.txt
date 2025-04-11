cmake_minimum_required(VERSION 3.3.0...4.0.0)
project(AdvancedDataStructure VERSION 0.1.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/BinarySearchTree)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Aula3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Aula4)

set (BINARY_TREE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BinarySearchTree/binarySearchTree.h)

set(AULAS
    Aula3
    Aula4
)

foreach(EDA ${AULAS})
    add_executable(${EDA} main.cpp)
    target_include_directories(${EDA} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${BINARY_TREE_DIR})
    target_link_libraries(${EDA} ${CMAKE_THREAD_LIBS_INIT})
endforeach(EDA ${AULAS})

