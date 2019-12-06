#ifndef CHESSBOARD_RENDERER_H
#define CHESSBOARD_RENDERER_H

#include <chessboard.h>

class ChessBoardRenderer {
private:
	virtual void draw_board_bg(ChessBoard &board) = 0;
	virtual void draw_board_cells(ChessBoard &board) = 0;
public:
	virtual void draw(ChessBoard &board) = 0;
	virtual ~ChessBoardRenderer() = default;
};

#endif
