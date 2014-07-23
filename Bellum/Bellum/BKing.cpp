#include "BKing.h"

char BKing::GetPiece()
{
	return 'K';
}

bool BKing::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	// Set up the delta variables
	int rowDelta = dRow - cRow;
	int colDelta = dCol - cCol;

	// Calculate valid move
	if (((rowDelta >= -1) && (rowDelta <= 1)) && ((colDelta >= -1) && (colDelta <= 1)))
	{
		return true;
	} 
	// Super Pawn Sacrifice
	else if (arrayBoard[dRow][dCol]->GetPiece() == 'S')
	{
		if (GetFaction() == 'G')
		{
			if (arrayBoard[dRow][dCol]->GetFaction() == 'G')
			{
				arrayBoard[dRow][dCol] = 0;
				return true;
			}
		}
		else if (GetFaction() == 'D')
		{
			if (arrayBoard[dRow][dCol]->GetFaction() == 'D')
			{
				arrayBoard[dRow][dCol] = 0;
				return true;
			}
		}
	}

	// Castling
	// Make sure the king stays on the same row
	if (dRow == cRow)
	{
		// GUARDIANS CHECKS
		if (GetFaction() == 'G')
		{
			// Check that king is in original position
			if ((cCol == 4) && (cRow == 1))
			{
				// Movement check
				// Left Rook
				if (dCol == cCol - 2)
				{
					if (arrayBoard[1][1] != 0)
					{
						// Check that rook is still in original place
						if (arrayBoard[1][1]->GetPiece() == 'R')
						{
							// Make sure the square the rook goes to is free
							if (arrayBoard[1][3] != 0)
							{
								return false;
							}
							else
							{
								// Move rook to square
								arrayBoard[1][3]	= arrayBoard[1][1];
								arrayBoard[1][1]	= 0;
								return true;
							}
						}
					}
				}
				// Right Rook
				else if (dCol == cCol + 3)
				{
					if (arrayBoard[1][8] != 0)
					{
						// Check rook is in original place
						if (arrayBoard[1][8]->GetPiece() == 'R')
						{
							// Make sure the squares in between are free
							if ((arrayBoard[1][6] != 0) || (arrayBoard[1][5] != 0))
							{
								return false;
							}
							else
							{
								// Move rook to square
								arrayBoard[1][6]	= arrayBoard[1][8];
								arrayBoard[1][8]	= 0;
								return true;
							}
						}
					}
				}
			}
		}
		// DEMONS CHECKS
		else
		{
			// Check that king is in original position
			if ((cCol == 4) && (cRow == 8))
			{
				// Movement check
				if (dCol == cCol - 2)
				{
					if (arrayBoard[8][1] != 0)
					{
						// Check that rook is still in original place
						if (arrayBoard[8][1]->GetPiece() == 'R')
						{
							// Make sure the square the rook goes to is free
							if (arrayBoard[8][3] != 0)
							{
								return false;
							}
							else
							{
								// Move rook to square
								arrayBoard[8][3]	= arrayBoard[8][1];
								arrayBoard[8][1]	= 0;
								return true;
							}
						}
					}
				}
				else if (dCol == cCol + 3)
				{
					if (arrayBoard[8][8] != 0)
					{
						// Check rook is in original place
						if (arrayBoard[8][8]->GetPiece() == 'R')
						{
							// Make sure the squares in between are free
							if ((arrayBoard[8][6] != 0) || (arrayBoard[8][5] != 0))
							{
								return false;
							}
							else
							{
								// Move rook to square
								arrayBoard[8][6]	= arrayBoard[8][8];
								arrayBoard[8][8]	= 0;
								return true;
							}
						}
					}
				}
			}
		}
	}

	

	return false;
}