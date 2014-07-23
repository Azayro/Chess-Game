#ifndef BKNIGHT_H
#define BKNIGHT_H

#include "BPiece.h"

/*----------------------------------------
---------------BKNIGHT CLASS---------------
----------------------------------------*/
class BKnight : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BKnight(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BKnight() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'N' to represent the Knight
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	knights valid moves
	Pre:	If piece on current square has a 'N'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};

#endif