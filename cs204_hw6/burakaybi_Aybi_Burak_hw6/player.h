#include "board.h"

class Player
{
private:
	Board &playerBoard;
	int ID;

public:
	Player(Board& board, int id): playerBoard(board), ID(id){ }
	bool guess(int row, int col);
	bool wins();
};

