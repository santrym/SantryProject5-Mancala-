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

	vector<int> mainBoard(14);





public:

	Board();

	Board(vector<int> v);

	Board CopyBoard(Board b);

	vector<Board> getNeighbors();





}