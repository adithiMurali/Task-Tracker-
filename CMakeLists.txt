cmake_minimum_required(VERSION 3.10)
project(TaskTracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find nlohmann_json package
find_package(nlohmann_json REQUIRED)

# Add executable
add_executable(task-cli
    main.cpp
    Task.cpp
    TaskManager.cpp
)

# Link libraries
target_link_libraries(task-cli PRIVATE nlohmann_json::nlohmann_json) 