#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cctype>
#include <algorithm> 
#include "Board.h"
using namespace std;


/**
*		
*		Board Class for Mancala. Contains all of the board operations needed to perform the game.	
*
*		Mike Santry
*		12/15/13
*
**/



/*
*	Standard Board Constructor with no input fields
*/
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


/*
*	Board constructor when the board contents are known. Aka in  vector.
*/
Board::Board(vector<int> v)
{
	goAgain = false;
	mainBoard = v;
	playerScore = mainBoard[6];
	oppositionScore = mainBoard[13];
	
}



/*
*	This constructor is used when we have a Board and we want the baord after a certain bowl "i" has been played.	
*/
Board::Board(Board inBoard, int i)
{
	goAgain = false;
	vector<int> tempBoard = inBoard.CopyCurrentBoard();
	int count = tempBoard[i];
	int place = i - 1;
	vector<int> retBoard = inBoard.CopyCurrentBoard();
	retBoard[i] = 0;
	//if bowl is played by player 2
	if(i > 6){
		while(count != 0)
		{
			// If last marble is placed in mancala they get to go again.
			if(count == 1 && place == 6){
				goAgain = true;
			}

			// Stops player 1 from scoring for the other player
			if(place == -1){
				place = 12;
			}

			// Tests to see if last marble placement has significance.
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

			// Distributes marbles to appropriate bowls.
			else{
				retBoard[place] = retBoard[place] + 1;
				count = count - 1;
				place = place - 1;
			}
		}
	}

	// If bowl is played by Player 1.
	else{
		while(count != 0)
		{
			
			// Keeps place counter on track so that Player 2 can score.
			if(place == -1){
				place = 13;
			}


			// Tests if last marble is placed in mancala, if it is the player will get to go agian
			if(count == 1 && place == 13){
				goAgain = true;
			}

			
			// Stops player 2 from scoring for the other player.
			if(place == 6){
				place = 5;
			}


			// Tests if last marble placement has significance.
			if(count == 1){
				if(retBoard[place] == 0 && place != 6 && place != 13 && place < 6){
					if(retBoard[12 - place] != 0){
						retBoard[13] = retBoard[13] + retBoard[place] + retBoard[12-place];
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
			
			// Distributes marbles appropriately.
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



/*
*	Returns the number of marbles in a particular bowl "a".
*/
int Board::BowlMarbles(int a)
{
	int retVal = mainBoard[a];
	return retVal;
}



/*
*	Returns the current board state in form of a vector of integers.
*/
vector<int> Board::CopyCurrentBoard()
{
	// creates a vector a the is equal to currentBoard vector.
	vector<int> a = mainBoard;
	return a;
}





/*
*	Gets the neighbors for player 2
*/
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




/*
*	Gets neighbors for player 1.
*/
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




/*
*	Returns the player 2's score
*/
int Board::PlayerScore()
{
	int retVal = playerScore * 4;

	retVal = retVal + mainBoard[7] + mainBoard[8] + mainBoard[9] + mainBoard[10] + mainBoard[11] + mainBoard[12];
	/*
	for (int i = 7; i < 13; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	*/
	return retVal;
}




/*
*	Returns Player 1's score.
*/
int Board::OppositionScore()
{
	int retVal = oppositionScore * 4;

	retVal = retVal + mainBoard[0] + mainBoard[1] + mainBoard[2] + mainBoard[3] + mainBoard[4] + mainBoard[5];
	/*
	for (int i = 0; i < 6; ++i)
	{
		retVal = retVal + mainBoard[i];
	}
	*/
	return retVal;
}



/*
*	returns the Difference between the scores of player 1 and 2.
*/
int Board::Difference()
{
	int difference = playerScore - oppositionScore;
	return difference;
}



/*
*	 returns the goAgain field which determines if a board allows the current player to go again.
*/
bool Board::GoAgainer()
{
	return goAgain;
}



/*
*	Used for computer when playing 1 player game. Determines the best possible move givena board and a depth.
*/
vector<int> Board::MinMax(Board b, int depth, bool doMax)
{
	vector<int> retVec(2);

	//base Case
	if(depth == 1){
		//This is if the lowest level is Player 1's turn.
		if(doMax == true){

			int maxVal = -100;
			int place = 10;
			vector<Board> brds = b.getNeighborsOppositionMove(b);
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

		// This is if the lowest level is Player 2's turn.
		if(doMax == false){

			int minVal = 100;
			int place = 10;
			vector<Board> brds = b.getNeighborsPlayerMove(b);
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

	/*
	* Non base case. uses recursion if the depth is divisible by 2.
	* It gets the player 1's possible moves and chooses the best one, to prepare for the worst case scenario
	* then it uses recursion with that board.
	*/
	if(depth % 2 == 0){
		vector<Board> nebs = b.getNeighborsPlayerMove(b);
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


	/*
	* Non base case. uses recursion if the depth is not divisible by 2.
	* Finds player 2's possible moves and uses recursion on each one to go deeper and find the best possible choice at the 
	* given level.
	*/
	if(depth % 2 == 1){
		vector<Board> nebs = b.getNeighborsOppositionMove(b);
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







