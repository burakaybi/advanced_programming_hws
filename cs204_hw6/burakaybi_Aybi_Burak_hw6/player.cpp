#include "player.h"


bool Player::guess(int row, int col)
{
	bool result=playerBoard.makeAHit(row, col);
	return result;
}

bool Player::wins()
{
	bool result = playerBoard.checkIfPlayerWon();
	return result;
}

