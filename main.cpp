#include <stdio.h>
#include <iostream>
#include <exception>
#include <chessboard.h>
#include <chessboard_renderer_sdl.h>
#include <chrono>
#include <thread>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

int main(int argc, char *argv[])
{	
	int width = 560; 
	int height = 560;

	int xpos = (SCREEN_WIDTH - width) / 2;
	int ypos = (SCREEN_HEIGHT - height) / 2;
	
	ChessBoardRenderer_SDL renderer{SCREEN_WIDTH, SCREEN_HEIGHT};
	ChessBoard board(&renderer);

	board.set_geometry(xpos, ypos, width, height);
	board.create_cells(8, 8);

	int value = 1;

	for (int i = 0; i < board.get_rows(); i++) {
		if (i % 2 == 0)
			value = 1;
		else 
			value = 0;

		for (int j = 0; j < board.get_columns(); j++) {
			board.set_cell(i, j, value);
			value = !value;
		}
	}
	
	board.draw();

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		
	return EXIT_SUCCESS;
}
