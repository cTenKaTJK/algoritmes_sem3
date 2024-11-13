cmake_minimum_required(VERSION 3.28)


set(PROJECT_NAME lab13)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

FILE( COPY "${CMAKE_CURRENT_SOURCE_DIR}/src"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )

include_directories("/src")
add_executable("${PROJECT_NAME}" main.cpp add.hpp)
