#include "BPiece.h"

BPiece::BPiece(char faction)
{
	Faction = faction;
}

BPiece::~BPiece()
{

}

char BPiece::GetPiece()
{
	return 0;
}

char BPiece::GetFaction()
{
	return Faction;
}

bool BPiece::IsMoveLegal(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
		BPiece* dest = arrayBoard[dRow][dCol];
		BPiece* curr = arrayBoard[cRow][cCol];
		if ((dest == 0) || (Faction != dest->GetFaction()) || (dest->GetPiece() == 'S') && (curr->GetPiece() == 'K'))
		{
			return CheckSquares(cRow, cCol, dRow, dCol, arrayBoard);
		}
	
		return false;
}

bool CheckSquares(int cRow, int cCol, int dRow, int dCol, BPiece* arrayBoard[10][10])
{
	return 0;
}