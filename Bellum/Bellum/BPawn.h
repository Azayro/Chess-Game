#ifndef BPAWN_H
#define BPAWN_H

#include "BPiece.h"

/*----------------------------------------
---------------BPAWN CLASS---------------
----------------------------------------*/
class BPawn : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BPawn(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BPawn() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'P' to represent the Pawn
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	pawns valid moves
	Pre:	If piece on current square has a 'P'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif