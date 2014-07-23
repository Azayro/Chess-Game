#include "BBoard.h"

BBoard::BBoard() 
{
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			arrayBoard[row][col] = 0;
		}
	}
	// Dynamically allocate and place guardian pieces
	for (int col = 0; col < 10; col++) 
	{
		arrayBoard[2][col] = new BPawn('G');
	}

	arrayBoard[1][0] = new BSuperPawn('G');
	arrayBoard[1][1] = new BRook('G');
	arrayBoard[1][2] = new BKnight('G');
	arrayBoard[1][3] = new BBishop('G');
	arrayBoard[1][4] = new BKing('G');
	arrayBoard[1][5] = new BQueen('G');
	arrayBoard[1][6] = new BBishop('G');
	arrayBoard[1][7] = new BKnight('G');
	arrayBoard[1][8] = new BRook('G');
	arrayBoard[1][9] = new BSuperPawn('G');

	arrayBoard[0][0] = new BGuard('G');
	arrayBoard[0][9] = new BGuard('G');


	// Dynamically allocate and place demon pieces
	for (int col = 0; col < 10; col++) 
	{
		arrayBoard[7][col] = new BPawn('D');
	}

	arrayBoard[8][0] = new BSuperPawn('D');
	arrayBoard[8][1] = new BRook('D');
	arrayBoard[8][2] = new BKnight('D');
	arrayBoard[8][3] = new BBishop('D');
	arrayBoard[8][4] = new BKing('D');
	arrayBoard[8][5] = new BQueen('D');
	arrayBoard[8][6] = new BBishop('D');
	arrayBoard[8][7] = new BKnight('D');
	arrayBoard[8][8] = new BRook('D');
	arrayBoard[8][9] = new BSuperPawn('D');

	arrayBoard[9][0] = new BGuard('D');
	arrayBoard[9][9] = new BGuard('D');
}

BBoard::~BBoard() 
{
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			delete arrayBoard[row][col];
			arrayBoard[row][col] = 0;
		}
	}
}

void BBoard::OutputBoard() 
{
	using namespace std;
	const int squareWidth = 4;
	const int squareHeight = 3;

	for (int row = 0; row < 10*squareHeight; row++) 
	{
		int Row = row/squareHeight;
		// Output side numbering
		if (row % 3 == 1) 
		{
			cout << ' ' << (char)('1' + 8 - Row) << ' ';
		} 
		else 
		{
			cout << "   ";
		}

		// Output the chess board with pieces in appropriate places
		for (int col = 0; col < 10*squareWidth; col++) 
		{
			int Col = col/squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && arrayBoard[9-Row][Col] != 0) 
			{
				if ((col % 4) == 1) 
				{
					cout << arrayBoard[9-Row][Col]->GetFaction();
				} 
				else 
				{
					cout << arrayBoard[9-Row][Col]->GetPiece();
				}
			} 
			else 
			{
				if ((Row + Col) % 2 == 1) 
				{
					cout << '*';
				} 
				else 
				{
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	// Output bottom numbering
	for (int row = 0; row < squareHeight; row++) 
	{
		if (row % 3 == 1) 
		{
			cout << "   ";
			for (int col = 0; col < 10 * squareWidth; col++) 
			{
				int Col = col/squareWidth;
				if ((col % 4) == 1) 
				{
					cout << (Col);
				} 
				else 
				{
					cout << ' ';
				}
			}
			cout << endl;
		} 
		else 
		{
			for (int col = 1; col < 9*squareWidth; col++) {
				cout << ' ';
			}
			cout << endl;
		}
	}
}

bool BBoard::CanMove(char faction) 
{
	// Run through all pieces
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			if (arrayBoard[row][col] != 0) 
			{
				// If it is a piece of the current player, see if it has a legal move
				if (arrayBoard[row][col]->GetFaction() == faction) 
				{
					for (int dRow = 0; dRow < 10; dRow++) 
					{
						for (int dCol = 0; dCol < 10; dCol++) 
						{
							if (arrayBoard[row][col]->IsMoveLegal(row, col, dRow, dCol, arrayBoard)) 
							{
								// Make move and check whether king is in check
								BPiece* temp					= arrayBoard[dRow][dCol];
								arrayBoard[dRow][dCol]			= arrayBoard[row][col];
								arrayBoard[row][col]			= 0;
								
								bool canMove = !Check(faction);
								// Undo the move
								arrayBoard[row][col]			= arrayBoard[dRow][dCol];
								arrayBoard[dRow][dCol]			= temp;
								if (canMove) 
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool BBoard::Check(char faction) 
{
	// Find the kings coordinates
	int kingR = 0;
	int kingC = 0;
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			if (arrayBoard[row][col] != 0) 
			{
				if (arrayBoard[row][col]->GetFaction() == faction) 
				{
					if (arrayBoard[row][col]->GetPiece() == 'K') 
					{
						kingR = row;
						kingC = col;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			if (arrayBoard[row][col] != 0) 
			{
				if (arrayBoard[row][col]->GetFaction() != faction) 
				{
					if (arrayBoard[row][col]->IsMoveLegal(row, col, kingR, kingC, arrayBoard)) 
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void BBoard::PromotionCheck(char faction)
{
	// Run through all pieces
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			if (arrayBoard[row][col] != 0) 
			{
				// If it is a piece of the current player, see if its a pawn
				if (arrayBoard[row][col]->GetFaction() == faction) 
				{
					if(arrayBoard[row][col]->GetPiece() == 'P')
					{
						if (faction == 'G')
						{	// Replace the pawn with a queen
							if (row == 9)
							{
								arrayBoard[row][col] = 0;
								arrayBoard[row][col] = new BQueen('G');
							}
						}
						else if (faction == 'D')
						{	// Replace the pawn with a queen
							if (row == 0)
							{
								arrayBoard[row][col] = 0;
								arrayBoard[row][col] = new BQueen('D');
							}
						}
					}
				}
			}
		}
	}
}

void BBoard::EnPassantCheck(char faction)
{
	// Run through all pieces
	for (int row = 0; row < 10; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			if (arrayBoard[row][col] != 0) 
			{	
				// If it is a piece of the current player, see if its a pawn
				if ((arrayBoard[row][col]->GetFaction() == faction) && (arrayBoard[row][col]->GetPiece() == 'P')) 
				{
					if (faction == 'G')
					{
						if (arrayBoard[row - 1][col] != 0)
						{
							if (arrayBoard[row - 1][col]->GetFaction() == 'D')
							{
								if (arrayBoard[row - 1][col]->GetPiece() == 'P')
								{
									arrayBoard[row - 1][col] = 0;
								}
							}
						}
					}
					else if (faction == 'D')
					{
						if (arrayBoard[row + 1][col] != 0)
						{
							if (arrayBoard[row + 1][col]->GetFaction() == 'G') 
							{
								if (arrayBoard[row + 1][col]->GetPiece() == 'P')
								{
									arrayBoard[row + 1][col] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
}