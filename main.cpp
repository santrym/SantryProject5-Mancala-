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
*		Main For Mancala Game.	
*
*		Mike Santry
*		12/15/13
*
**/


int main()
{
	// Tells if player 2 can go again
	bool goAgainOpposition = true;

	// Tells if Player 1 can go again
	bool goAgainPlayer = true;

	// Used to check for valid inputs
	bool validInput = false;

	// Used as switch for when a game is over
	bool gameOn = true;

	// the Bowl about to be played
	int currentBowl = 0;

	// Holds number of players
	int players = 0;

	// Holds the Depth... and smugness.
	int JohnnyDepp = 0;

	// Holds the current board
	Board theBoard = Board();

	// Holds the board state, aka the number of marbles in each bowl/mancala.
	vector<int> theActualBoard = theBoard.CopyCurrentBoard();



	//asks user for the number of players.
	cout << "How many players 1 or 2?" << endl << endl;
	cin >> players;
	while(players != 1 && players != 2){
		cout << "invalid gimme a real number of players chump" << endl << endl;
		cin >> players;
	}



	// Asks user for the depth
	cout << endl << "What depth would you like the computer to use?" << endl;
	cin >> JohnnyDepp;
	while(JohnnyDepp < 1){
		cout << "invalid give me a real depth greater than 0." << endl;
		cin >> JohnnyDepp;
	}




	cout << "Let the game begin!" << endl << endl << endl;



	//gives instructions for a 1 player game.
	if(players == 1){
		cout << "To play, when prompted, enter the number of the bowl you would like to play" << endl; 
		cout << "You are playing as the bottom row aka numbers 7 through 12. The numbering is as follows: " << endl << endl;
		cout << "     0     1     2     3    4    5  " << endl << "     12    11    10    9    8    7"  << endl << endl;
	}




	//gives instructions for a 2 player.
	if(players == 2){
		cout << "To play, when prompted, enter the number of the bowl you would like to play" << endl;
		cout << "Player 1 plays the bottom row aka numbers 7 through 12" << endl;
		cout << "Player 2 plays as the top row aka numbers 0 through 5" << endl;

	}




	// Gives reading time before posting new instructions
	int timeWaster = 100000000;
	while(timeWaster > 1){
		timeWaster = timeWaster - 1;
	}



	cout << "To win, you must either get 25 points, or have a larger number of points" << endl;
	cout << "than your opponant when either your or your opponants row is empty." << endl << endl ;

	

	// Gives reading time before posting new instructions
	int timeWasterr = 100000000;
	while(timeWasterr > 1){
		timeWasterr = timeWasterr - 1;
	}




	cout << "GOOD LUCK AND ENJOY THE GAME!!!" << endl << endl;



	// Gives reading time before posting new instructions
	int timeWasterz = 10000000;
	while(timeWasterz > 1){
		timeWasterz = timeWasterz - 1;
	}



	//Prints out the original state of the board
	cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
	<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

	cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
	<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;


	//prints starting scores
	cout << endl;
	cout << "Player 1:  " << theActualBoard[6] << endl;
	cout << "Player 2:  " << theActualBoard[13] << endl;





	/*
	*	2 player game.
	*/
	if(players == 2){
		while(gameOn)
		{
			// Player 1's turn
			while(goAgainPlayer){
				cout << "Player 1's Turn" << endl;
				cout << "choose a bowl" << endl << endl << "Choice:  ";
				cin	>> currentBowl;
				
				// Checks if bowl chosen is valid
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

				
				// Tests to see if the game is over
				if(theBoard.PlayerScore() > 96 || (theActualBoard[7] == 0 && theActualBoard[8] == 0 && 
					theActualBoard[9] == 0 && theActualBoard[10] == 0 && theActualBoard[11] == 0 && theActualBoard[12] == 0)){
					gameOn = false;
				}

				// Tests to see if player 1 gets another turn.
				if(theBoard.GoAgainer()){
					goAgainPlayer = true;
					cout << "Go again player 1!" << endl;
				}
				else{
					goAgainPlayer = false;
				}

			}

			goAgainPlayer = true;

			
			//Player 2's Turn.
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
					
					
					// Checks if game is over.
					if(theBoard.OppositionScore() > 96 || (theActualBoard[0] == 0 && theActualBoard[1] == 0 && 
						theActualBoard[2] == 0 && theActualBoard[3] == 0 && theActualBoard[4] == 0 && theActualBoard[5] == 0)){
						gameOn = false;
					}


					//Tests if Player 2 gets to go again
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






	/*
	*	1 Player Game
	*/

	else{
		while(gameOn)
		{
			while(goAgainPlayer){
				cout << "Player 1's Turn" << endl;
				
				// Asks player 1 for their bowl choice.
				cout << "choose a bowl" << endl << endl << "Choice:  ";
				cin	>> currentBowl;
				

				// Makes sure the bowl chosen was valid.
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

				// Stores the new board info with the new bowl.
				Board tb = Board(theBoard, currentBowl);
				theBoard = tb;
				theActualBoard = theBoard.CopyCurrentBoard();


				// Prints out the Board and Scores
				cout << "Player 2" << "        " << theActualBoard[0] << "   " << theActualBoard[1] << "   " 
				<< theActualBoard[2] << "   " << theActualBoard[3] << "   " << theActualBoard[4] << "   " << theActualBoard[5] << "          Player 1" << endl;

				cout << "Mancala" <<"         " << theActualBoard[12] << "   " << theActualBoard[11] << "   " << theActualBoard[10]
				<< "   " << theActualBoard[9] << "   " << theActualBoard[8] << "   " << theActualBoard[7] << "          " << "Mancala" << endl;

				cout << endl;
				cout << "Player 1:  " << theActualBoard[6] << endl;
				cout << "Player 2:  " << theActualBoard[13] << endl << endl;

				
				// Tests to see if the game is over.
				if(theBoard.PlayerScore() > 96 || (theActualBoard[7] == 0 && theActualBoard[8] == 0 && 
					theActualBoard[9] == 0 && theActualBoard[10] == 0 && theActualBoard[11] == 0 && theActualBoard[12] == 0)){
					gameOn = false;
				}


				// Tests to see if player 1 gets to go again.
				if(theBoard.GoAgainer()){
					goAgainPlayer = true;
					cout << "Go again player 1!" << endl;
				}
				else{
					goAgainPlayer = false;
				}

			}

			goAgainPlayer = true;


			// Player 2's Turn
			if(gameOn == true){
				while(goAgainOpposition){	
					

					cout << "Player 2's Turn. " << endl;
					bool boolVal = true;
					if(JohnnyDepp % 2 == 0 && JohnnyDepp != 1){
						boolVal = false;
					}

					// Gets the vector int which ayay[0] contains the bowl the best outcome for given depth.
					vector<int> ayay = theBoard.MinMax(theBoard, JohnnyDepp, boolVal);

					currentBowl = ayay[0];

					if(theActualBoard[currentBowl] == 0){
						bool next = true;
						int a = 0;
						while(next == true){
							if(theActualBoard[a] != 0){
								currentBowl = a;
								next = false;
							}
							a = a + 1;
						}
					}


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


					if(theBoard.OppositionScore() > 96 || (theActualBoard[0] == 0 && theActualBoard[1] == 0 && 
						theActualBoard[2] == 0 && theActualBoard[3] == 0 && theActualBoard[4] == 0 && theActualBoard[5] == 0)){
						gameOn = false;
					}


					
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



};


#endif

