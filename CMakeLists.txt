cmake_minimum_required(VERSION 3.24)
project (ocm_desktop)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package (Threads)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})


add_executable(ocm_desktop main.cpp game.cpp game.h tempo.cpp tempo.h board.cpp board.h bishop.cpp bishop.h piece.cpp piece.h logic.cpp logic.h const.h attacked_board.cpp attacked_board.h)

target_link_libraries(ocm_desktop ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries (ocm_desktop Threads::Threads)
