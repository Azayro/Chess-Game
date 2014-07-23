#ifndef BBOARD_H
#define BBOARD_H

#include "BPiece.h"
#include "BBishop.h"
#include "BGuard.h"
#include "BKing.h"
#include "BKnight.h"
#include "BPawn.h"
#include "BQueen.h"
#include "BRook.h"
#include "BSuperPawn.h"
#include <iostream>


class BBoard
{
public:
	//-----CONSTRUCTOR-----
	// Allocates the pieces to the array
	BBoard();

	//-----DESTRUCTOR-----
	// Deletes all elements of the array to free
	// up any memory used
	~BBoard();

	/*---------------OUTPUT BOARD---------------
	Function to output the board to the console
	PRE:	When the board needs to be updated
	POST:	Outputs the board with current
			locations of the pieces
	------------------------------------------*/
	void OutputBoard();

	/*-----------------CAN MOVE-----------------
	Function to see if the player can move
	PRE:	This is the parameter that needs to
			stay true for the game to continue
	POST:	If the king is able to move then it
			is not checkmate so therefore
			return: TRUE otherwise
			return: FALSE and the game will be
			over.
	-----------------------------------------*/
	bool CanMove(char faction);

	/*------------------CHECK------------------
	Function used when needed to see if king
	is in check
	PRE:	When a function needs to check if
			the king is or will be in check 
			after a move.
	POST:	The function returns: TRUE if the
			king is in check otherwise FALSE
			is returned.
	-----------------------------------------*/
	bool Check(char faction);

	//----------SPECIAL MOVE CHECKS----------

	/*------------PROMOTION CHECK------------
	Called within the game loop to see if any
	pawns are in the last row to be promoted.
	PRE:	Called within the game loop to
			check pawns.
	POST:	If any pawns are in the last row
			then a queen replaces them.
	---------------------------------------*/
	void PromotionCheck(char faction);

	/*------------EN PASSANT CHECK------------
	Called within the game loop to see if an
	En Passant move has been completed.
	PRE:	Called within game loop to check
			pawn locations
	POST:	If any pawn locations match the
			rules for en passant the enemy
			pawn is removed from play.
	----------------------------------------*/
	void EnPassantCheck(char faction);
	

	BPiece* arrayBoard[10][10];
};

#endif