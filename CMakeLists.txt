cmake_minimum_required(VERSION 3.10)
project(DeepLearningModels)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(backend)
add_subdirectory(ui)

add_executable(DeepLearningModels
    main.cpp
)

target_link_libraries(DeepLearningModels PRIVATE DeepLearningUI DeepLearningBackend)


enable_testing()

add_test(NAME TestDataLoader COMMAND TestDataLoader)
add_test(NAME TestLinearRegression COMMAND TestLinearRegression)
add_test(NAME TestUtils COMMAND TestUtils)
add_test(NAME TestMultipleLinearRegression COMMAND TestMultipleLinearRegression)
