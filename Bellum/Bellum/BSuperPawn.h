#ifndef BSUPERPAWN_H
#define BSUPERPAWN_H

#include "BPiece.h"

/*----------------------------------------
---------------BSUPERPAWN CLASS---------------
----------------------------------------*/
class BSuperPawn : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BSuperPawn(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BSuperPawn() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'S' to represent the Super Pawn
	char GetPiece();

	//---------------CHECK SQUARE---------------
	// This function is used to determine the
	// super pawns valid moves
	//Pre:	If piece on current square has a 'S'
	//Post:	If destination square is valid
	//		return: TRUE if not valid
	//		return: FALSE
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif