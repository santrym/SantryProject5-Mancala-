#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cctype>
#include <algorithm> 
#include "Board.h"
#include "Heap.h"

using namespace std;


/**
*
*
*		Main For Mancala Game.	
*
*
**/


int main()
{
	bool validInput = false;

	bool gameOn = true;

	int currentBowl = 0;

	Board theBoard = Board();

	vector<int> theActualBoard = theBoard.CopyCurrentBoard(); 

	cout << "Let the game begin!" << endl << endl << endl;

	cout << 

	cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
	<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

	cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
	<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;

	cout << endl;
	cout << "Player 1:  " << theActualBoard[6] << endl;
	cout << "Player 2:  " << theActualBoard[13] << endl;


	while(gameOn)
	{
		cout << "choose a bowl" << endl << endl << "Choice:  ";
		cin	>> currentBowl;
		while(validInput == false){
			if(currentBowl < 7 || currentBowl > 12){
				cout << "invalid input try again" << endl << endl << "Choice:  ";
				cin >> currentBowl;
			}
			else{
				validInput = true;
			}
		}
		


	}




};


#endif

