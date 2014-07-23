#ifndef BROOK_H
#define BROOK_H

#include "BPiece.h"

/*----------------------------------------
---------------BQUEEN CLASS---------------
----------------------------------------*/
class BRook : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BRook(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BRook() {};

private:
	//---------------GET PIECE---------------
	// Inherited class to output a 'R' to represent the Rook
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	rooks valid moves
	Pre:	If piece on current square has a 'R'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif