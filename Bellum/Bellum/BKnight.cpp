#include "BKnight.h"

char BKnight::GetPiece()
{
	return 'N';
}

bool BKnight::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	// Whether or not the squares are occupied the Knight can still move as it can jump
	if ((cCol == dCol + 1) || (cCol == dCol - 1)) 
	{
		if ((cRow == dRow + 2) || (cRow == dRow - 2)) 
		{
			return true;
		}
	}
	else if ((cCol == dCol + 2) || (cCol == dCol - 2)) 
	{
		if ((cRow == dRow + 1) || (cRow == dRow - 1)) 
		{
			return true;
		}
	}
	return false;
}