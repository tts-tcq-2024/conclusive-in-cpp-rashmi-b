cmake_minimum_required(VERSION 3.14)
project(cleancode)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_compile_options("--coverage")
add_executable(
  cleancode
  typewise-alert.cpp
  typewise-alert.tests.cpp
)
target_link_libraries(
  cleancode
  GTest::gmock_main
  gtest_main
  gmock_main
  gcov
)

include(GoogleTest)
# gtest_discover_tests(cleancode)
