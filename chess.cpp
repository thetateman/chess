

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "square.h"

using namespace std;

int initBoard(vector<vector<square>> *inputBoard) // initialize all the pieces in their original locations
{
	for (int i = 0; i < 8; ++i)  //initialize white pawns
	{
		((*inputBoard)[1][i]).setPiece('P');
		((*inputBoard)[1][i]).setColor('w');
	}
	for (int i = 0; i < 8; ++i)  //initialize black pawns
	{
		((*inputBoard)[6][i]).setPiece('P');
		((*inputBoard)[6][i]).setColor('b');
	}
	//initialize back row of white pieces
	((*inputBoard)[0][0]).setPiece('R');
	((*inputBoard)[0][0]).setColor('w');

	((*inputBoard)[0][1]).setPiece('N');
	((*inputBoard)[0][1]).setColor('w');

	((*inputBoard)[0][2]).setPiece('B');
	((*inputBoard)[0][2]).setColor('w');

	((*inputBoard)[0][3]).setPiece('Q');
	((*inputBoard)[0][3]).setColor('w');

	((*inputBoard)[0][4]).setPiece('K');
	((*inputBoard)[0][4]).setColor('w');

	((*inputBoard)[0][5]).setPiece('B');
	((*inputBoard)[0][5]).setColor('w');

	((*inputBoard)[0][6]).setPiece('N');
	((*inputBoard)[0][6]).setColor('w');

	((*inputBoard)[0][7]).setPiece('R');
	((*inputBoard)[0][7]).setColor('w');

	// initialize back row of black pieces

	((*inputBoard)[7][0]).setPiece('R');
	((*inputBoard)[7][0]).setColor('b');

	((*inputBoard)[7][1]).setPiece('N');
	((*inputBoard)[7][1]).setColor('b');

	((*inputBoard)[7][2]).setPiece('B');
	((*inputBoard)[7][2]).setColor('b');

	((*inputBoard)[7][3]).setPiece('Q');
	((*inputBoard)[7][3]).setColor('b');

	((*inputBoard)[7][4]).setPiece('K');
	((*inputBoard)[7][4]).setColor('b');

	((*inputBoard)[7][5]).setPiece('B');
	((*inputBoard)[7][5]).setColor('b');

	((*inputBoard)[7][6]).setPiece('N');
	((*inputBoard)[7][6]).setColor('b');

	((*inputBoard)[7][7]).setPiece('R');
	((*inputBoard)[7][7]).setColor('b');

	return 0;
}

int printBoard(vector<vector<square>> inputBoard)
{
	printf("\n");
	for (int i = 7; i >= 0; --i)
	{
		printf("%i |  ", i + 1);
		for (int j = 0; j < 8; ++j)
		{
			char printablePiece = inputBoard[i][j].getPiece();
			printf("%c   ", printablePiece);
		}
		printf("\n  |\n");
	}
	printf("______________________________________\n");
	printf("     a   b   c   d   e   f   g   h\n");
	printf("\n");
	return 0;
}
bool isValidMove(int startCo[], int endCo[], vector<vector<square>> inputBoard, bool whitesTurn, vector<vector<int>> moveSet)
{
	
	square *startingSquare = &(inputBoard[startCo[0]][startCo[1]]);
	if (startingSquare->getPiece() == EMPTY)  //check if piece exists in square
	{
		printf("no piece on that square.\n");
		return false;
	}
	//check if square contains right color piece.
	else if ((whitesTurn && startingSquare->getColor() == 'b') || (!whitesTurn && startingSquare->getColor() == 'w'))
	{
		printf("You don't have a piece on that square.\n");
		return false;
	}

	//check if move is in moveSet



	return true;
}

int generateMoveSet(int startingCo[2], bool whitesTurn, vector<vector<square>> inputBoard, vector<vector<int>> *moveSet)
{
	square* startingSquare = &(inputBoard[startingCo[0]][startingCo[1]]);
	if (startingSquare->getPiece() == EMPTY)  //check if piece exists in square
	{
		printf("no piece on that square.\n");
		return 0;
	}
	//check if square contains right color piece.
	else if ((whitesTurn && startingSquare->getColor() == 'b') || (!whitesTurn && startingSquare->getColor() == 'w'))
	{
		printf("You don't have a piece on that square.\n");
		return 0;
	}

	vector<int> move(2);
	char piece = startingSquare->getPiece();
	switch (piece)
	{
	case 'N':
		
		move.at(0) = startingCo[0] + 2; move.at(1) = startingCo[1] + 1;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] + 1; move.at(1) = startingCo[1] + 2;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] - 2; move.at(1) = startingCo[1] - 1;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] - 1; move.at(1) = startingCo[1] - 2;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] + 1; move.at(1) = startingCo[1] - 2;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] + 2; move.at(1) = startingCo[1] - 1;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] - 2; move.at(1) = startingCo[1] + 1;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		move.at(0) = startingCo[0] - 1; move.at(1) = startingCo[1] + 2;
		if (move.at(0) >= 0 && move.at(0) <= 7 && move.at(1) >= 0 && move.at(1) <= 7)
		{
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
		}
		break;
	case 'R':
		for (int i = startingCo[0] + 1; i < 8; ++i)
		{
			move.at(0) = i; move.at(1) = startingCo[1];
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
			else
			{
				//hit own piece, end loop
				break;
			}
			if (inputBoard.at(move.at(0)).at(move.at(1)).getColor() != EMPTY)
			{
				//hit other piece, add move and end loop
				break;
			}
		}
		for (int i = startingCo[0] - 1; i >= 0; --i)
		{
			move.at(0) = i; move.at(1) = startingCo[1];
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
			else
			{
				//hit own piece, end loop
				break;
			}
			if (inputBoard.at(move.at(0)).at(move.at(1)).getColor() != EMPTY)
			{
				//hit other piece, add move and end loop
				break;
			}
		}
		for (int i = startingCo[1] + 1; i < 8; ++i)
		{
			move.at(0) = startingCo[0]; move.at(1) = i;
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
			else
			{
				//hit own piece, end loop
				break;
			}
			if (inputBoard.at(move.at(0)).at(move.at(1)).getColor() != EMPTY)
			{
				//hit other piece, add move and end loop
				break;
			}
		}
		for (int i = startingCo[1] - 1; i >= 0; --i)
		{
			move.at(0) = startingCo[0]; move.at(1) = i;
			if (!((inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'w' && whitesTurn) || (inputBoard.at(move.at(0)).at(move.at(1)).getColor() == 'b' && !whitesTurn)))
			{
				moveSet->push_back(move);
			}
			else
			{
				//hit own piece, end loop
				break;
			}
			if (inputBoard.at(move.at(0)).at(move.at(1)).getColor() != EMPTY)
			{
				//hit other piece, add move and end loop
				break;
			}
		}
		break;
	case 'P':
		break;
	case 'B':
		break;
	case 'Q':
		break;
	case 'K':

		break;
	default:
		printf("error, no piece there.");
	}
	
	// generate original move set

	// remove elements based on obstructions

	return moveSet->size(); //number of possible moves -- unsigned int
}

int main()
{
	bool running = true;
	int turnCounter = 0;
	bool whitesTurn = true;
	string moveEntry = "";
	square newSquare;
	vector<vector<square>> board(8, vector<square> (8, newSquare));   // accessed with [row][column]
	initBoard(&board);

	printf("Hello, welcome to Chess!\nLicensed under GPL (GNU General Public License) in 2020 by Tate Smith & Reed Smith.\n\n");

	printf("Input moves in the format \"coordinates of piece\"(space)\"target coordinates\". Coordinates should be in the format \"column\"\"row\".\n\n\n");
	while (running)
	{
		if (whitesTurn)
		{
			printf("It's White's turn, enter a move.\n");
		}
		else
		{
			printf("It's Black's turn, enter a move.\n");
		}
		
		getline(cin, moveEntry);

		if (moveEntry.length() != 5)
		{
			printf("Please use the right move format.\n");
			continue;
		}
		else if ((moveEntry.at(0) < 'a') || (moveEntry.at(0) > 'h') || (moveEntry.at(1) < '1') || (moveEntry.at(1) > '8'))
		{
			printf("Please enter starting coordinates in the right format.\n");
			continue;
		}
		else if ((moveEntry.at(3) < 'a') || (moveEntry.at(3) > 'h') || (moveEntry.at(4) < '1') || (moveEntry.at(4) > '8'))
		{
			printf("Please enter target coordinates in the right format.\n");
			continue;

		}
		int startCo[] = { moveEntry.at(1) - 49, moveEntry.at(0) - 97 };
		int endCo[] = { moveEntry.at(4) - 49, moveEntry.at(3) - 97 };

		square* startSquare = &(board[startCo[0]][startCo[1]]);

		vector<vector<int>> moveSet;
		if (generateMoveSet(startCo, whitesTurn, board, &moveSet) == 0)
		{
			printf("not a valid move\n");
			//continue;
		}
		
		//printf("%i, %i\n", moveSet.at(0).at(0), moveSet.at(0).at(1));

		//DEBUG: print move set
		for (unsigned int i = 0; i < moveSet.size(); ++i)
		{
			printf("%i, %i\n", moveSet.at(i).at(0), moveSet.at(i).at(1));
		}

		if (!isValidMove(startCo, endCo, board, whitesTurn, moveSet))
		{
			printf("That is not a valid move.\n");
			continue;
		}

		//printf("%i    %i\n", startCo[0], startCo[1]);
		//empty starting square and fill new square
		
		board[endCo[0]][endCo[1]].setColor(startSquare->getColor());
		board[endCo[0]][endCo[1]].setPiece(startSquare->getPiece());
		startSquare->setColor(EMPTY);
		startSquare->setPiece(EMPTY);

		printBoard(board);
		whitesTurn = !whitesTurn;
		++turnCounter;
		
	}


}

