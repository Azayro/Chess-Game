#include "BPiece.h"

/*----------------------------------------
---------------BKING CLASS---------------
----------------------------------------*/
class BKing : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BKing(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BKing() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'K' to represent the King
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	kings valid moves
	Pre:	If piece on current square has a 'K'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};