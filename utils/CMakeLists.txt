cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 14)

project(utilslib)

include_directories(
        include
)

set(SRC_SOURCES
        src/FileLoader.cpp
        src/StringHelper.cpp
        )

# This is a make target, so you can do a "make projArunner"
set(UTILS_LIB utilslib)

add_library(${UTILS_LIB} STATIC ${SRC_SOURCES})

MESSAGE(PROJECT_SOURCE_DIR  : ${PROJECT_SOURCE_DIR})

target_include_directories(${UTILS_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/include)

