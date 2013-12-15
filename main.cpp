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
	bool goAgainOpposition = true;

	bool goAgainPlayer = true;

	bool validInput = false;

	bool gameOn = true;

	int currentBowl = 0;

	int players = 0;

	Board theBoard = Board();

	vector<int> theActualBoard = theBoard.CopyCurrentBoard();

	cout << "How many players 1 or 2?" << endl << endl;

	cin >> players;
	while(players != 1 && players != 2){
		cout << "invalid gimme a real number of players chump" << endl << endl;
		cin >> players;
	}

	cout << "Let the game begin!" << endl << endl << endl;

	cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
	<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

	cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
	<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;

	cout << endl;
	cout << "Player 1:  " << theActualBoard[6] << endl;
	cout << "Player 2:  " << theActualBoard[13] << endl;


	if(players == 1){
		while(gameOn)
		{
			while(goAgainPlayer){
				cout << "Player 1's Turn" << endl;
				cout << "choose a bowl" << endl << endl << "Choice:  ";
				cin	>> currentBowl;
				validInput = false;
				while(validInput == false){
					if(currentBowl < 7 || currentBowl > 12){
						cout << "invalid input try again" << endl << endl << "Choice:  ";
						cin >> currentBowl;
					}
					else{
						validInput = true;
					}
				}

				Board tb = Board(theBoard, currentBowl);
				theBoard = tb;
				theActualBoard = theBoard.CopyCurrentBoard();

				cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
				<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

				cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
				<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;

				cout << endl;
				cout << "Player 1:  " << theActualBoard[6] << endl;
				cout << "Player 2:  " << theActualBoard[13] << endl << endl;

				

				if(theBoard.PlayerScore() > 24 || (theActualBoard[0] == 0 && theActualBoard[1] == 0 && 
					theActualBoard[2] == 0 && theActualBoard[3] == 0 && theActualBoard[4] == 0 && theActualBoard[5] == 0)){
					gameOn = false;
				}

				if(theBoard.GoAgainer()){
					goAgainPlayer = true;
					cout << "Go again player 1!" << endl;
				}
				else{
					goAgainPlayer = false;
				}

			}

			goAgainPlayer = true;

			if(gameOn == true){
				while(goAgainOpposition){	
					cout << "Player 2's Turn. " << endl;

					cout << "choose a bowl" << endl << endl << "Choice:  ";
					cin	>> currentBowl;
					goAgainOpposition = false;
					while(validInput == false){
						if((currentBowl < 0) || (currentBowl > 5)){
							cout << "invalid input try again" << endl << endl << "Choice:  ";
							cin >> currentBowl;
						}
						else{
							validInput = true;
						}
					}

					Board tbt = Board(theBoard, currentBowl);
					theBoard = tbt;
					theActualBoard = theBoard.CopyCurrentBoard();

					cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
					<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

					cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
					<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;

					cout << endl;
					cout << "Player 1:  " << theActualBoard[6] << endl;
					cout << "Player 2:  " << theActualBoard[13] << endl << endl;
					
					if(theBoard.GoAgainer()){
						goAgainOpposition = true;
						cout << "Go again player 2!" << endl;
					}
					else{
						goAgainOpposition = false;
					}
				}
				goAgainOpposition = true;			
			}
			
		


		}
	}


	else{
		while(gameOn)
		{
			

			


			cout << "Player 2's Turn. " << endl;		

		}

	}



};


#endif

