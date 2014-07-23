#include "BQueen.h"

char BQueen::GetPiece()
{
	return 'Q';
}

bool BQueen::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	int rowOffset = (dRow - cRow > 0) ? 1 : -1;
	int colOffset = (dCol - cCol > 0) ? 1 : -1;

	int Row, Col;

	if ((dCol - cCol == dRow - cRow) || (dCol - cCol == cRow - dRow)) 
	{
		// Check all squares that will be passed on the way to destination are empty
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
	else if (cRow == dRow) 
	{
		// Check all squares that will be passed on the way to destination are empty
		for (int Col = cCol + colOffset; Col !=  dCol; Col = Col + colOffset) 
		{
			if (arrayBoard[cRow][Col] != 0) 
			{
				return false;
			}
		}
		return true;
	} 
	else if (dCol == cCol) 
	{
		// Make sure that all invervening squares are empty
		for (int Row = cRow + rowOffset; Row !=  dRow; Row = Row + rowOffset) 
		{
			if (arrayBoard[Row][cCol] != 0) 
			{
				return false;
			}
		}
		return true;
	} 
	return false;
}