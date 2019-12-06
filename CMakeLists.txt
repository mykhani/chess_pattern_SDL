cmake_minimum_required(VERSION 3.3)

project(chessPattern)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)

file(GLOB SRCS
        ${PROJECT_SOURCE_DIR}/**.cpp
)

add_executable(drawChessPattern main.cpp ${SRCS})

target_include_directories(drawChessPattern
	PRIVATE
	${PROJECT_SOURCE_DIR}
	${SDL_INCLUDE_DIRS}
	)

target_link_libraries(drawChessPattern
	${SDL2_LIBRARIES}
	)
