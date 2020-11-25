// chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "square.h"

using namespace std;

int initBoard(vector<vector<square>> *inputBoard) // initialize all the pieces in thier original locations
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
	((*inputBoard)[7][0]).setColor('w');

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
	for (int i = 7; i >= 0; --i)
	{
		for (int j = 7; j >= 0; --j)
		{
			char printablePiece = inputBoard[i][j].getPiece();
			printf("%c  ", printablePiece);
		}
		printf("\n\n");
	}
	return 0;
}
int main()
{
	bool running = true;
	int turnCounter = 0;
	bool whitesTurn = true;
	string moveEntry = "";
	square newSquare;
	vector<vector<square>> board(8, vector<square> (8, newSquare));
	initBoard(&board);
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
		
		
		printBoard(board);
		
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
