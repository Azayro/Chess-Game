#ifndef BQUEEN_H
#define BQUEEN_H

#include "BPiece.h"

/*----------------------------------------
---------------BQUEEN CLASS---------------
----------------------------------------*/
class BQueen : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BQueen(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BQueen() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'Q' to represent the Queen
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	queens valid moves
	Pre:	If piece on current square has a 'Q'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif