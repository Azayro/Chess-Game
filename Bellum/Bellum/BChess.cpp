#include "BChess.h"

BChess::BChess()
{
	playerTurn = 'G';
}
BChess::~BChess()
{

}

void BChess:: Menu()
{
	system("cls");

	using namespace std;

	char selection;

	cout << "----------WELCOME TO BELLUM----------\n\n";
	cout << "                 MENU\n\n";
	cout << "S - Start New Game\n";
	cout << "L - Load Game (Coming Soon)\n";
	cout << "H - Info/Help\n";
	cout << "E - Exit\n\n";
	cout << "Input one of the characters to the left of the selections - ";
	cin >> selection;

	// Switch statement to decide where to take the player.
	switch (selection)
	{
		// If the user decides to start a new game
		case 'S':
			Game();
			break;
		// If the user decides to load a game (Not yet implemented)
		case 'L':
			break;
		// If the user wishes to see information and help for the game
		case 'H':
			Info();
			break;
		// If the user wishes to leave the game
		case 'E':
			break;
	}
}

void BChess::Info()
{
	system("cls");

	using namespace std;

	char leave;

	cout << "Welcome to Bellum. A twist on Chess." << endl;
	cout << "The 0-9 on the bottom and left hand side are grid co-ordinates used to play the game." << endl;
	cout << "First input the row and then the column of the piece you wish to move." << endl;
	cout << "Then input the row and then the column of the square you wish to move the piece to. \n\n";

	cout << "Main Menu - Hit a Character and Enter";
	cin >> leave;

	Menu();
}

void BChess::Game() 
{
	system("cls");
	do
	{
		NextMove(bellumBoard.arrayBoard);
		// Checks to see if any pawns could be promoted
		bellumBoard.PromotionCheck(playerTurn);
		// Checks to see if en passant was done
		bellumBoard.EnPassantCheck(playerTurn);
		// Conditional operator used here to alternate between the players
		playerTurn = (playerTurn == 'G') ? 'D' : 'G';
	} while (!GameOverCheck());
	bellumBoard.OutputBoard();
	system("pause");
}

void BChess::NextMove(BPiece* board[10][10]) 
{
	using namespace std;
	bool validMove = false;
	while (!validMove)
	{
		bellumBoard.OutputBoard();

		// Variables for co ordinates
		int currPos, currRow, currCol;
		int destPos, destRow, destCol;


		// Get input and convert to coordinates
		cout << playerTurn << "'s Move, choose a piece: ";

		cin >> currPos;

		// Convert the inputted two digit number into row and column coordinates.
		currRow = (currPos / 10);
		currCol = (currPos % 10);


		cout << "Where would you like to move it?: ";

		cin >> destPos;


		destRow = (destPos / 10);
		destCol = (destPos % 10);

		// Check that the indices are in range
		// and that the source and destination are different
		if ((currRow >= 0 && currRow <= 9) && (currCol >= 0 && currCol <= 9) &&
			(destRow >= 0 && destRow <= 9) && (destCol >= 0 && destCol <= 9)) 
		{
			// Additional checks in here
			BPiece* currPiece = board[currRow][currCol];
			// Check that the piece is the correct color
			if ((currPiece != 0) && (currPiece->GetFaction() == playerTurn)) 
			{
				// Check that the destination is a valid destination
				if (currPiece->IsMoveLegal(currRow, currCol, destRow, destCol, board)) 
				{
					// Make the move
					BPiece* temp			= board[destRow][destCol];
					board[destRow][destCol]	= board[currRow][currCol];
					board[currRow][currCol]	= 0;
					// Make sure that the current player is not in check
					if (!bellumBoard.Check(playerTurn)) 
					{
						delete temp;
						validMove = true;
					} 
					else 
					{	// Undo the last move
						board[currRow][currCol] = board[destRow][destCol];
						board[destRow][destCol]	= temp;

						cout << "You are in check, protect your king!" << endl;
						Sleep(5000);
					}
				}
			}
		}

		if (!validMove) 
		{	
			// Outputs a message to let the player know that their choice was invalid
			cout << "Invalid Move, Please make another" << endl;
			Sleep(3000);
		}
		system("cls");
	}
}

bool BChess::GameOverCheck() 
{
	// Check that the current player can move
	// If not, we have a stalemate or checkmate
	bool canMove(false);
	canMove = bellumBoard.CanMove(playerTurn);
	if (!canMove) 
	{
		if (bellumBoard.Check(playerTurn)) 
		{
			playerTurn = (playerTurn == 'G') ? 'D' : 'G';
			std::cout << "Checkmate, " << playerTurn << " Wins!" << std::endl;
		} 
		else 
		{
			std::cout << "Stalemate!" << std::endl;
		}
	}
	return !canMove;
}
