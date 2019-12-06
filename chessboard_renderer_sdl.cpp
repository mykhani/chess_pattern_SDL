#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <chessboard_renderer_sdl.h>

void ChessBoardRenderer_SDL::draw_board_bg(ChessBoard &board)
{
	// Draw the board background
	SDL_Rect box;

	board.get_geometry(&box.x, &box.y, &box.w, &box.h);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &box);
}

void ChessBoardRenderer_SDL::draw_board_cells(ChessBoard &board)
{
	Cell cell;

	for (int i = 0; i < board.get_rows(); i++) {
		for (int j = 0; j < board.get_columns(); j++) {
			cell =  board.get_cell(i, j);
			
			SDL_Rect box;

			box.x = cell.x;
			box.y = cell.y;
			box.w = cell.width;
			box.h = cell.height;

			if (cell.value) /* black box */
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			else /* white box */
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			
			SDL_RenderFillRect(renderer, &box);
		}
	}
}

ChessBoardRenderer_SDL::ChessBoardRenderer_SDL(int width, int height)
	: window_width(width), window_height(height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                throw std::runtime_error("Could not initialize sdl2" + std::string(SDL_GetError()));
        }

	window = SDL_CreateWindow(
			"chess_pattern",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			window_width, window_height,
			SDL_WINDOW_SHOWN
			);

	if (window == NULL) {
		throw std::runtime_error("Could not create sdl2 window" + std::string(SDL_GetError()));
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);

	// clear window
	SDL_RenderClear(renderer);
}

void ChessBoardRenderer_SDL::draw(ChessBoard &board)
{
	draw_board_bg(board);

	draw_board_cells(board);

	SDL_RenderPresent(renderer);
}

ChessBoardRenderer_SDL::~ChessBoardRenderer_SDL()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
