cmake_minimum_required(VERSION 3.13)

project(RAN_SETI_CPP_TP
    VERSION 1.0
    DESCRIPTION "This project is part of an object-oriented programming RAN module of the Master 2 programme in Embedded Systems and Information Processing from the Institut Polytechnique de Paris."
    LANGUAGES CXX)
    
include_directories(${CMAKE_SOURCE_DIR}/include) # choosing header files folder


# choosing cpp file folders
file(GLOB SRC_SOURCES src/*.cpp)
file(GLOB LIB_SOURCES lib/*.cpp)
add_executable(sensorHandler ${SRC_SOURCES} ${LIB_SOURCES})

set_target_properties(sensorHandler PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}) # defining the output file directory as the root TP folder


target_include_directories(sensorHandler PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(sensorHandler PRIVATE cxx_std_20) # selecting the compiler

