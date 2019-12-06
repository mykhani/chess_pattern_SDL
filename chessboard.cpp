#include <chessboard.h>

void ChessBoard::set_geometry(int x, int y, int width, int height)
{       
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void ChessBoard::get_geometry(int *x, int *y, int *width, int *height)
{       
	*x = this->x;
	*y = this->y;
	*width = this->width;
	*height = this->height;
}

int ChessBoard::get_rows()
{
	return rows;
}

int ChessBoard::get_columns()
{
	return cols;
}

void ChessBoard::set_cell(int row, int col, int value)
{
	Cell &cell = cells[row][col];

	cell.value = value;
}

Cell ChessBoard::get_cell(int row, int col)
{
	return cells[row][col];
}

void ChessBoard::create_cells(int rows, int cols)
{	
	int cell_width = width / cols;
	int cell_height = height / rows;

	this->rows = rows;
	this->cols = cols;

	for (int i = 0; i < rows; i++) {
		std::vector<Cell> board_row;
		for (int j = 0; j < cols; j++) {
			Cell board_cell;
			board_cell.x = j * cell_width + x;
                        board_cell.y = i * cell_height + y;
                        board_cell.width = cell_width;
                        board_cell.height = cell_height;
			board_cell.value = 0;

			board_row.push_back(board_cell);
			
		}

		cells.push_back(board_row);
	}
}

void ChessBoard::draw()
{
	renderer->draw(*this);
}

ChessBoard::ChessBoard(ChessBoardRenderer *renderer)
{
	this->renderer = renderer;
}
