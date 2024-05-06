cmake_minimum_required(VERSION 3.28)
project(Buscaminas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp
        Menu.cpp
        Headers/Menu.h
        Headers/Game_settings.h
        Game_settings.cpp
        Game.cpp
        Headers/Game.h
        Headers/Global_settings.h
)
add_executable(Buscaminas ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Buscaminas sfml-system sfml-window sfml-graphics sfml-audio sfml-network)