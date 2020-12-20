cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

MESSAGE(Project dir : ${PROJECT_SOURCE_DIR})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/utils/include
)

set(APP_SOURCES
        src/main.cpp
        )

# This is a make target, so you can do a "make projArunner"
set(APPLICATION_NAME day04p1)

add_executable(${APPLICATION_NAME} ${APP_SOURCES})

target_link_libraries(${APPLICATION_NAME}
        utilslib
        )


