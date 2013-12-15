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
				if(retBoard[place] == 0 && place != 6 && place != 13 && place > 6){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + 1 + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
						count = count - 1;
						place = place - 1;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = place - 1;
					}
				}
				else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = place - 1;
					}
			}
			else{
				retBoard[place] = retBoard[place] + 1;
				count = count - 1;
				place = place - 1;
			}
		}
	}
	else{
		while(count != 0)
		{
			if(place == -1){
				place = 13;
			}

			if(count == 1 && place == 13){
				goAgain = true;
			}

			

			if(place == 6){
				place = 5;
			}

			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13 && place < 6){
					if(retBoard[12 - place] != 0){
						retBoard[6] = retBoard[6] + retBoard[place] + retBoard[12-place];
						retBoard[place] = 0;
						retBoard[12 - place] = 0;
						count = count - 1;
						place = place - 1;
					}
					else{
						retBoard[place] = retBoard[place] + 1;
						count = count - 1;
						place = place - 1;
					}
				}
				else{
					retBoard[place] = retBoard[place] + 1;
					count = count - 1;
					place = place - 1;
				}
			}
			else{
			retBoard[place] = retBoard[place] + 1;
			count = count - 1;
			place = place - 1;
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





vector<Board> Board::getNeighborsOppositionMove(Board b)
{
	vector<Board> retVec;

	for (int i = 0; i < 6; ++i)
	{
		Board retB = Board(b, i);
		retVec.push_back(retB);
	}

	return retVec;
}



vector<Board> Board::getNeighborsPlayerMove(Board b)
{
	vector<Board> retVec;


	for (int i = 7; i < 13; ++i)
	{
		Board retB = Board(b, i);
		retVec.push_back(retB);
	}

	return retVec;
}



int Board::PlayerScore()
{
	int retVal = playerScore;
	/*
	for (int i = 7; i < 13; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	*/
	return retVal;
}



int Board::OppositionScore()
{
	int retVal = oppositionScore;
	/*
	for (int i = 0; i < 6; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	*/
	return retVal;
}



int Board::Difference()
{
	int difference = playerScore - oppositionScore;
	return difference;
}



bool Board::GoAgainer()
{
	return goAgain;
}



/**
//  Get oppositions best option
int Board::MinMax(Board b, int depth)
{
	
	if(depth % 2 == 0){
		vector<int> rettt= b.MinMaxOppLast(Board b, int depth);
		
		//returns the move value
		return rettt[0] + 7;
	}


	else{
		b.MinMaxPlayerLast(Board b, int depth);
	}


}




vector<int> Board::MinMaxOppLast(Board b, int depth)
{
	vector<int> MinMaxVals(2);
	MinMaxVals[0] = 0;
	MinMaxVals[1] = 0;


	//base case
	if(depth == 1){
		vector<int> retVBC(2);
		int minVal = 100;
		int place = 10;
		vector<Board> brds = b.getNeighborsOppositionMove();
		for (int i = 0; i < 6; ++i)
		{
		 	Board aa = brds[i];
		 	int val = aa.Difference();
		 	if(val < minVal){
		 		minVal = val;
		 		place = i;
		 	}
		} 
		retVBC[0] = place;
		retVBC[1] = minVal;
		return retVBC 

	}


	// players turn.
	if(depth % 2 == 0){
		vector<int> veectorRat(2);
		int maxVall = -100;
		int placeMax = 111;
		vector<Board> bbrds = b.getNeighborsPlayerMove();
		for (int i = 0; i < 6; ++i)
		{
			Board bbb = bbrds[i];
			vector<int> loopVals = MinMaxOppLast(bbb, depth - 1);
			if(loopVals[1] > maxVall){
				maxVall = loopVals[1];
				placeMax = i;
			}	
		}
		veectorRat[0] = placeMax;
		veectorRat[1] = maxVall;
		return veectorRat;
	}


	// Opponants turn.
	else{
		vector<int> veectorRatt(2);
		int minVall = -100;
		int placeMin = 111;
		for (int i = 7; i < 13; ++i)
		{
			vector<int> loopVals = MinMaxOppLast(b, depth - 1);
			if(loopVals[1] > maxVall){
				minVall = loopVals[1];
				placeMin = loopVals[0];
			}
		}
	}
}



int Board::MinMaxPlayerLast(Board b, int depth)
{
	
}
**/



vector<int> Board::MinMax(Board b, int depth, bool doMax)
{
	vector<int> retVec(2);

	//base Case
	if(depth == 1){
		if(doMax == true){

			int maxVal = -100;
			int place = 10;
			vector<Board> brds = b.getNeighborsPlayerMove();
			for (int i = 0; i < 6; ++i)
			{
			 	Board aa = brds[i];
			 	int val = aa.Difference();
			 	if(val > maxVal){
			 		maxVal = val;
			 		place = i;
			 	}
			} 
			retVec[0] = place;
			retVec[1] = maxVal;
			return retVec;
			
		}
		if(doMax == false){

			int minVal = 100;
			int place = 10;
			vector<Board> brds = b.getNeighborsOppositionMove();
			for (int i = 0; i < 6; ++i)
			{
			 	Board aa = brds[i];
			 	int val = aa.Difference();
			 	if(val < minVal){
			 		minVal = val;
			 		place = i;
			 	}
			}
			retVec[0] = place;
			retVec[1] = minVal;
			return retVec;
		}


	}

	if(depth % 2 == 0){
		vector<Board> nebs = b.getNeighborsOppositionMove();
		int MinVaal = 1000;
		int MinPlace = 100;
		for (int i = 0; i < 6; ++i)
		{	
			Board a = nebs[i];
			if(a.Difference() < MinVaal){
				MinVaal = a.Difference();
				MinPlace = i;
			}
		}
		bool bovo = !doMax;
		retVec[0] = MinPlace;
		retVec[1] = MinVaal;

		vector<int> aVC = b.MinMax(nebs[MinPlace], depth - 1, bovo);
		
		return aVC;
	}


	if(depth % 2 == 1){
		vector<Board> nebs = b.getNeighborsPlayerMove();
		int maxVal = -111;
		int MaxPlace = 100;
		for (int i = 0; i < 6; ++i)
		{
			Board heyo = nebs[i];
			bool bavo = !doMax;
			vector<int> pah = heyo.MinMax(heyo, depth-1, bavo);
			if(pah[1] > maxVal){
				maxVal = pah[1];
				MaxPlace = i;
			}

		}
		retVec[0] = MaxPlace;
		retVec[1] = maxVal;
		return retVec;
	}
}



