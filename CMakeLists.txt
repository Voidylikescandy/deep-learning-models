cmake_minimum_required(VERSION 3.10)
project(UnivariateLinearRegression)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.9.2
)
FetchContent_MakeAvailable(spdlog)

add_executable(UnivariateLinearRegression
    src/main.cpp
    src/data_loader.cpp
    src/linear_regression.cpp
    src/utils.cpp
)

# add_executable(TestDataLoader tests/test_data_loader.cpp src/data_loader.cpp)
# add_executable(TestLinearRegression tests/test_linear_regression.cpp src/linear_regression.cpp src/utils.cpp)
# add_executable(TestUtils tests/test_utils.cpp src/utils.cpp)

# Link spdlog
target_link_libraries(UnivariateLinearRegression PRIVATE spdlog::spdlog)