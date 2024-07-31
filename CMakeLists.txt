cmake_minimum_required(VERSION 3.10)
project(DeepLearningModels)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# FetchContent for spdlog
include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.9.2
)
FetchContent_MakeAvailable(spdlog)

# FetchContent for Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(DeepLearningModels
    src/main.cpp
    src/data_loader.cpp
    src/univariate_linear_regression.cpp
    src/utils.cpp
)

# Link spdlog
target_link_libraries(DeepLearningModels PRIVATE spdlog::spdlog)

# Add test executables
add_executable(TestDataLoader tests/test_data_loader.cpp src/data_loader.cpp)
target_link_libraries(TestDataLoader PRIVATE gtest gtest_main spdlog::spdlog)
target_include_directories(TestDataLoader PUBLIC include)

add_executable(TestLinearRegression tests/test_univariate_linear_regression.cpp src/univariate_linear_regression.cpp src/utils.cpp)
target_link_libraries(TestLinearRegression PRIVATE gtest gtest_main spdlog::spdlog)
target_include_directories(TestLinearRegression PUBLIC include)

add_executable(TestUtils tests/test_utils.cpp src/utils.cpp)
target_link_libraries(TestUtils PRIVATE gtest gtest_main spdlog::spdlog)
target_include_directories(TestUtils PUBLIC include)

# Enable testing
enable_testing()

# Add tests
add_test(NAME TestDataLoader COMMAND TestDataLoader)
add_test(NAME TestLinearRegression COMMAND TestLinearRegression)
add_test(NAME TestUtils COMMAND TestUtils)