cmake_minimum_required(VERSION 3.12)
project(CPP)

set(CMAKE_CXX_STANDARD 11)

# Add header files directory
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/hospital/Patient.cpp
)

# Add executable target
add_executable(CPP ${SOURCES})
