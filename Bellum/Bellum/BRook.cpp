#include "BRook.h"

char BRook::GetPiece()
{
	return 'R';
}

bool BRook::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	if (cRow == dRow) 
	{
		// If the player chooses to move the rook horizontally
		// Make sure that all invervening squares are empty
		int iColOffset = (dCol - cCol > 0) ? 1 : -1;
		for (int Col = cCol + iColOffset; Col !=  dCol; Col = Col + iColOffset) 
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
		// If the player chooses to move the rook vertically
		// Make sure that all invervening squares are empty
		int iRowOffset = (dRow - cRow > 0) ? 1 : -1;
		for (int Row = cRow + iRowOffset; Row !=  dRow; Row = Row + iRowOffset) 
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
