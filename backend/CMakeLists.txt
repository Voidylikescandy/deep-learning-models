cmake_minimum_required(VERSION 3.10)
project(DeepLearningBackend)

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
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Backend library
add_library(DeepLearningBackend
    src/data_loader.cpp
    src/univariate_linear_regression.cpp
    src/utils.cpp
    src/multiple_linear_regression.cpp
)

# Link spdlog to the backend library
target_link_libraries(DeepLearningBackend PRIVATE spdlog::spdlog)

# Include directories for backend
target_include_directories(DeepLearningBackend PUBLIC ${spdlog_SOURCE_DIR}/include)

# Add test executables
add_executable(TestDataLoader tests/test_data_loader.cpp)
target_link_libraries(TestDataLoader PRIVATE DeepLearningBackend gtest gtest_main spdlog::spdlog)
target_include_directories(TestDataLoader PUBLIC include)

add_executable(TestLinearRegression tests/test_univariate_linear_regression.cpp)
target_link_libraries(TestLinearRegression PRIVATE DeepLearningBackend gtest gtest_main spdlog::spdlog)
target_include_directories(TestLinearRegression PUBLIC include)

add_executable(TestUtils tests/test_utils.cpp)
target_link_libraries(TestUtils PRIVATE DeepLearningBackend gtest gtest_main spdlog::spdlog)
target_include_directories(TestUtils PUBLIC include)

add_executable(TestMultipleLinearRegression tests/test_multiple_linear_regression.cpp)
target_link_libraries(TestMultipleLinearRegression PRIVATE DeepLearningBackend gtest gtest_main spdlog::spdlog)
target_include_directories(TestMultipleLinearRegression PUBLIC include)
