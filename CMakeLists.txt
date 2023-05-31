cmake_minimum_required(VERSION 3.12)
project(DSA)

set(CMAKE_CXX_STANDARD 11)

# Add header files directory
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/hospital/Patient.cpp
    src/user/User.cpp
)

# Add executable target
add_executable(DSA ${SOURCES})
