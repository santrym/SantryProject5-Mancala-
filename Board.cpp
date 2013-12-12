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
	goAgain = false;
	vector<int> mainBoardd(14);
	mainBoard = mainBoardd;
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
	goAgain = false;
	mainBoard = v;
	playerScore = mainBoard[6];
	oppositionScore = mainBoard[13];

	
}


Board::Board(Board inBoard, int i)
{
	goAgain = false;
	vector<int> tempBoard = inBoard.CopyCurrentBoard();
	int count = tempBoard[i];
	int place = i - 1;
	vector<int> retBoard = inBoard.CopyCurrentBoard();
	retBoard[i] = 0;
	if(i > 6){
		while(count != 0)
		{
			if(count == 1 && place == 6){
				goAgain = true;
			}

			if(place == -1){
				place = 12;
			}
			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + retBoard[place] + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = i - 1;
					}
				}
				else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = i - 1;
					}
			}
			else{
				retBoard[place] = retBoard[place] + 1;
				count = count - 1;
				place = i - 1;
			}
		}
	}
	
	else{
		while(count != 0)
		{
			if(count == 1 && place == 13){
				goAgain = true;
			}

			if(place == -1){
				place = 13;
			}

			if(place == 6){
				place = 5;
			}

			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + retBoard[place] + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = i - 1;
					}
				}
				else{
					retBoard[place] = retBoard[place] + 1;
					count = count - 1;
					place = i - 1;
				}
			}
			else{
			retBoard[place] = retBoard[place] + 1;
			count = count - 1;
			place = i - 1;
			}
		}
	}

	mainBoard = retBoard;
	playerScore = mainBoard[6];
	oppositionScore = mainBoard[13];
}



int Board::BowlMarbles(int a)
{
	int retVal = mainBoard[a];
	return retVal;
}



vector<int> Board::CopyCurrentBoard()
{
	// creates a vector a the is equal to currentBoard vector.
	vector<int> a = mainBoard;
	return a;
}



/**

vector<Board> Board::getNeighborsOppositionMove()
{
	vector<Board> retVec;

	for (int i = 0; i < 6; ++i)
	{
		int count = BowlMarbles(i);
		int place = i - 1;
		vector<int> retBoard = mainBoard;
		retBoard[i] = 0;
		while(count != 0)
		{
			if(place == -1){
				place = 13;
			}
			if(place == 6){
				place = 5;
			}
			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + retBoard[place] + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = i - 1;
					}
				}
			}
			else{
			retBoard[place] = retBoard[place] + 1;
			count = count - 1;
			place = i - 1;
			}
		}
		Board neighborBoard = Board(retBoard);
		retVec.push_back(neighborBoard);
	}
	return retVec;

}

**/

/**

vector<Board> Board::getNeighborsPlayerMove()
{
	vector<Board> retVec;


	for (int i = 7; i < 13; ++i)
	{
		int count = BowlMarbles(i);
		int place = i - 1;
		vector<int> retBoard = mainBoard;
		retBoard[i] = 0;
		while(count != 0)
		{
			if(place == 6 && count == 1)
			{
				retBoard[6] = retBoard[6] + 1;

				Board aBor = Board(retBoard);
				vector<Board> mancalaBoards = aBor.getNeighborsPlayerMove();

				count = count - 1;
			}



			if(place == -1){
				place = 13;
			}

			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + retBoard[place] + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = i - 1;
					}
				}
			}
			
			retBoard[place] = retBoard[place] + 1;
			count = count - 1;
			place = i - 1;

		}
		Board neighborBoard = Board(retBoard);
		retVec.push_back(neighborBoard);
	}
	return retVec;

}

**/


int Board::PlayerScore()
{
	int retVal = 0;
	retVal = playerScore * 3;
	for (int i = 7; i < 13; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	return retVal;
}



int Board::OppositionScore()
{
	int retVal = 0;
	retVal = oppositionScore * 3;
	for (int i = 0; i < 6; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	return retVal;
}



int Board::Difference()
{
	int difference = playerScore - oppositionScore;
	return difference;
}









