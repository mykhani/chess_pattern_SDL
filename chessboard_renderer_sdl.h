#ifndef CHESSBOARDRENDERER_SDL_H
#define CHESSBOARDRENDERER_SDL_H

#include <chessboard.h>
#include <chessboard_renderer.h>
#include <SDL2/SDL.h>

class ChessBoardRenderer_SDL : public ChessBoardRenderer {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	void draw_board_bg(ChessBoard &board) override;
	void draw_board_cells(ChessBoard &board) override;
public:
	int window_width;
	int window_height;

	ChessBoardRenderer_SDL(int width, int height);
	~ChessBoardRenderer_SDL();

	virtual void draw(ChessBoard &board) override;
};

#endif
