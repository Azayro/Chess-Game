#ifndef BCHESS_H
#define BCHESS_H

#include "BBoard.h"
#include "BPiece.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>


class BChess
{
public:
	//----------CONSTRUCTOR----------
	BChess();
	//----------DESTRUCTOR----------
	~BChess();

	/*-------------------MENU-------------------
	A navigation system for the user to start a
	game or check information/help.
	PRE:	First function called when the game
			is run.
	POST:	Takes the user to a screen or the
			game depending on the input.
	------------------------------------------*/
	void Menu();

	/*-------------------INFO-------------------
	Displays information about the game. 
	PRE:	Selected at the main menu.
	POST:	Goes to main menu when a character
			is inputted.
	------------------------------------------*/
	void Info();

	/*-------------------GAME-------------------
	Contains the game loop. Which will continue
	to loop until the GameOverCheck function 
	returns true. Calls functions to run the
	game. Alternates the players.
	PRE:	First function called if at the menu
			Start Game is selected.
	POST:	Continues to loop until a parameter
			is met. Which comes from the
			function GameOverCheck.
	------------------------------------------*/
	void Game();

	/*----------------NEXT MOVE-----------------
	Requests the user input for the coordinates
	of the piece to move and the destination.
	Contains error checking and calls to
	functions in other classes to determine
	whether or not the move is valid.
	PRE:	Called by the Game function each
			time the game loops.
	POST:	Returns when a valid move has been
			entered.
	------------------------------------------*/
	void NextMove(BPiece* board[10][10]);

	/*-------------GAME OVER CHECK--------------
	Parameter of the game loop to determine 
	if the game is over or not.
	PRE:	Called as a parameter of the game
			loop.
	POST:	If game is not over then FALSE
			is returned otherwise TRUE is
			returned and a game over message
			is outputted to the screen.
	------------------------------------------*/
	bool GameOverCheck();

private:
	BBoard bellumBoard;
	char playerTurn;
};

#endif