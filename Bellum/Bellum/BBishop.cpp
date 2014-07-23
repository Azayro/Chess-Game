#include "BBishop.h"

char BBishop::GetPiece()
{
	return 'B';
}

bool BBishop::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
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
	return false;
}