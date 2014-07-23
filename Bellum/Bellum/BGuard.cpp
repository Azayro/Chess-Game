#include "BGuard.h"

char BGuard::GetPiece()
{
	return 'G';
}

bool BGuard::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	// Bishop valid moves
	int rowOffset = (dRow - cRow > 0) ? 1 : -1;
	int colOffset = (dCol - cCol > 0) ? 1 : -1;

	if ((dCol - cCol == dRow - cRow) || (dCol - cCol == cRow - dRow)) 
	{
		// Check all squares that will be passed on the way to destination are empty
		int Row, Col;

		for (Row = cRow + rowOffset, Col = cCol + colOffset; Row !=  dRow;
			Row = Row + rowOffset, Col = Col + colOffset)
		{
			if (arrayBoard[Row][Col] != 0) 
			{
				return false;
			}
		}
		return true;
	}

	// Knight valid moves
	// Can only jump if doing the knights move
	if ((cCol == dCol + 1) || (cCol == dCol - 1)) 
	{
		if ((cRow == dRow + 2) || (cRow == dRow - 2)) 
		{
			return true;
		}
	}

	if ((cCol == dCol + 2) || (cCol == dCol - 2)) 
	{
		if ((cRow == dRow + 1) || (cRow == dRow - 1)) 
		{
			return true;
		}
	}

	return false;
}
