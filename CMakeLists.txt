cmake_minimum_required(VERSION 3.16)

project(AniEngineDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pull in the AniEngine library (provided as a git submodule).
add_subdirectory(external/AniEngine)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE AniEngine::aniengine)
