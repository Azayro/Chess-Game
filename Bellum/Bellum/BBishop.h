#ifndef BBISHOP_H
#define BBISHOP_H

#include "BPiece.h"

/*----------------------------------------
---------------BBISHOP CLASS---------------
----------------------------------------*/
class BBishop : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BBishop(char faction) : BPiece(faction){}
	//----------DESTRUCTOR----------
	~BBishop() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'B' to represent the Bishop
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	bishops valid moves
	Pre:	If piece on current square has a 'B'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif