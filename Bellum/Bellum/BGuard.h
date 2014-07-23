#include "BPiece.h"

/*----------------------------------------
---------------BGUARD CLASS---------------
----------------------------------------*/
class BGuard : public BPiece
{

public:
	//----------CONSTRUCTOR-----------
	BGuard(char faction) : BPiece(faction){}
	//----------DECONSTRUCTOR----------
	~BGuard() {};

private:
	//----------GET PIECE----------
	// Inherited class to output a 'G' to represent the Guard
	char GetPiece();

	/*---------------CHECK SQUARE---------------
	This function is used to determine the
	rguards valid moves
	Pre:	If piece on current square has a 'G'
	Post:	If destination square is valid
			return: TRUE if not valid
			return: FALSE
	------------------------------------------*/
	bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);
};