#include "BPawn.h"

char BPawn::GetPiece()
{
	return 'P';
}

bool BPawn::CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	BPiece* dest = arrayBoard[dRow][dCol];
	if (dest == 0) 
	{
		// Destination square is unoccupied
		if (cCol == dCol) 
		{
			if (GetFaction() == 'G') 
			{
				if (dRow == cRow + 1) 
				{
					return true;
				}
				// Double move at the start
				else if (dRow == cRow + 2)
				{
					if (cRow == 2)
					{
						return true;
					}
				}
			} 
			else 
			{
				if (dRow == cRow - 1) 
				{
					return true;
				}
				// Double move at the start
				else if (dRow == cRow - 2)
				{
					if (cRow == 7)
					{
						return true;
					}
				}
			}
		}
	} 
	else 
	{
		// Moves diagonally if the position contains an opponents piece
		if ((cCol == dCol + 1) || (cCol == dCol - 1)) 
		{
			if (GetFaction() == 'G') 
			{
				if (dRow == cRow + 1) 
				{
					return true;
				}
			} 
			else 
			{
				if (dRow == cRow - 1) 
				{
					return true;
				}
			}
		}
	}
	
	// Part of En Passant Special Move
	if ((dCol == cCol + 1) || (dCol == cCol - 1))
	{
		if (GetFaction() == 'G')
		{
			if (dRow == cRow + 1)
			{
				if (arrayBoard[dRow - 1][dCol] != 0)
				{
					if (arrayBoard[dRow - 1][dCol]->GetFaction() == 'D')
					{
						if(arrayBoard[dRow - 1][dCol]->GetPiece() == 'P')
						{
							return true;
						}
					}
				}
			}
		}
		else if (GetFaction() == 'D')
		{
			if (dRow == cRow - 1)
			{
				if (arrayBoard[dRow + 1][dCol] != 0)
				{
					if (arrayBoard[dRow + 1][dCol]->GetFaction() == 'G')
					{
						if (arrayBoard[dRow + 1][dCol]->GetPiece() == 'P')
						{
							return true;
						}
					}
				}
			}
		}
	}
	

	return false;
}