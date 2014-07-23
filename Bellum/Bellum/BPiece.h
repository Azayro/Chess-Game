#ifndef BPIECE_H
#define BPIECE_H

/*----------------------------------------
---------------BPIECE CLASS---------------
----------------------------------------*/
class BPiece
{
public:
	//--------------CONSTRUCTOR---------------
	BPiece(char faction);
	//---------------DESTRUCTOR---------------
	~BPiece();

	//---------------GET PIECE----------------
	// Will be inherited by the pieces. 
	// Used to output a character that will represent the piece
	virtual char GetPiece() = 0;

	/*--------------GET FACTION---------------
	Will return the faction of the player
	PRE:	Program requires the faction of
			current player
	POST:	Returns the faction
	----------------------------------------*/
	char GetFaction();

	/*--------------IS MOVE LEGAL-------------
	This will check to see if the move made is
	a valid move. Will call CheckSquares
	----------------------------------------*/
	bool IsMoveLegal(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]);

private:
	/*-------------CHECK SQUARES--------------
	Inherited Function.
	Will be called by the IsMoveLegal function
	get valid moves of a piece
	PRE:	Valid move needs to be checked
	POST:	Returns either true or false
			for the specific piece depending
			on whether or not a valid move.
	----------------------------------------*/
	virtual bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10]) = 0;
	char Faction;
};

#endif