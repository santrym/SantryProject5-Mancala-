#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <cctype>
#include <algorithm> 
using namespace std;


class Board
{
private:

	int	playerScore;

	int oppositionScore;

	vector<int> mainBoard;

	bool goAgain;





public:

	Board();

	Board(vector<int> v);

	Board(Board inBoard, int i);

	int BowlMarbles(int a);

	vector<int> CopyCurrentBoard();

	//vector<Board> getNeighborsOppositionMove();

	//vector<Board> getNeighborsPlayerMove();

	Board CopyBoard(Board b);

	//vector<Board> getNeighbors();

	int PlayerScore();

	int OppositionScore();

	int Difference();

	bool GoAgainer();

	vector<Board> getNeighborsOppositionMove(Board b);

	vector<Board> getNeighborsPlayerMove(Board b);

	vector<int> MinMax(Board b, int depth, bool doMax);

};

#endif
