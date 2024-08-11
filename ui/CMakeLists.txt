cmake_minimum_required(VERSION 3.10)
project(DeepLearningUI)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(../backend/include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_library(DeepLearningUI
    src/menu.cpp
    src/menu_state.cpp
)

target_link_libraries(DeepLearningUI PRIVATE sfml-graphics sfml-window sfml-system DeepLearningBackend)
