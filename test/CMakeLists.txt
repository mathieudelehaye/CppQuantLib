cmake_minimum_required(VERSION 3.15)
project(CppQuantLibTests LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(CppQuantLibTests test_fintech_library.cpp)

# Include headers from the lib project
target_include_directories(CppQuantLibTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/../lib/include
)

# Link against GoogleTest and your shared library
set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/../output)
target_link_libraries(CppQuantLibTests
    PRIVATE
        gtest_main
        ${OUTPUT_DIR}/lib/libCppQuantLib.so
)

# Enable GoogleTest discovery for CTest
include(GoogleTest)
gtest_discover_tests(CppQuantLibTests)