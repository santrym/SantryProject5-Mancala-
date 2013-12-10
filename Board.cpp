#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cctype>
#include <algorithm> 
#include "Board.h"
using namespace std;





Board::Board()
{
	for (int i = 0; i < 6; ++i)
	{
		mainBoard[i] = 4;
	}
	for (int i = 7; i < 13; ++i)
	{
		mainBoard[i] = 4;
	}
	mainBoard[6] = 0;
	mainBoard[13] = 0;
	playerScore = 0;
	oppositionScore = 0;


}


Board::Board(vector<int> v)
{
	currentBoard = v;


	
}

int Board::bowlMarbles(int a)
{
	retVal = mainBoard[a];
	return retVal;
}


vector<int> Board::CopyCurrentBoard()
{
	// creates a vector a the is equal to currentBoard vector.
	vector<int> a = mainBoard;
	return a;
}



vector<Board> Board::getNeighbors()
{

}



