cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Include GTest and GMock
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googlemock/include)

# Link with GTest and GMock libraries
link_directories(${CMAKE_SOURCE_DIR}/googletest/build/lib)
target_link_libraries(MyProject gtest gmock)