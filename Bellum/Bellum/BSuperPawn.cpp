#include "BSuperPawn.h"

char BSuperPawn::GetPiece()
{
	return 'S';
}

bool BSuperPawn::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
		// Set up the delta variables
		int rowDelta = dRow - cRow;
		int colDelta = dCol - cCol;

		// Calculate valid move
		if (((rowDelta >= -2) && (rowDelta <= 2)) && ((colDelta >= -2) && (colDelta <= 2)))
		{
			return true;
		}
		return false;
}
