cmake_minimum_required(VERSION 3.10)
project(GradebookSystem)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add header include path
include_directories(definitions)
include_directories(headers)

# Add source files (with correct paths)
set(SOURCES
    main.cpp
    definitions/Gradebook.cpp
)

# Create executable
add_executable(GradebookSystem ${SOURCES})
