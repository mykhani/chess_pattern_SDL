#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// forward declaration
class ChessBoard;

#include <chessboard_renderer.h>
#include <vector>

struct Cell {
	int x;
	int y;
	int width;
	int height;
	int value;
};

class ChessBoard {
private:
	int x, y;
	int rows;
	int cols;
	int width;
	int height;

	std::vector<std::vector<Cell>> cells;
	ChessBoardRenderer *renderer;
public:
	ChessBoard(ChessBoardRenderer *renderer);

	void set_geometry(int x, int y, int width, int height);
	void get_geometry(int *x, int *y, int *width, int *height);
	int get_rows();
	int get_columns();
	void create_cells(int rows, int cols);
	void set_cell(int row, int col, int value);
	Cell get_cell(int row, int col);
	void draw();
};

#endif
