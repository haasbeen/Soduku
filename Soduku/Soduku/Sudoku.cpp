#include<iostream>
#include<vector>
#include <numeric>
#include <ranges>
#include <algorithm>
#include "sudokuFunctions.h"


using namespace std;

/*
dont repeat numbers
	vert, horz, 3x3 cube
	1-9 in every 3x3 cube
	Project by Has & Swag
*/

int main() {

	vector<vector<int>> board = generate_board();
	print_board(board);


	vector<vector<vector<int>>> x = calculate_possibilities(board);
		
	int y = 0;

	return 0;
}


