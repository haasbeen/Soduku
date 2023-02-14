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
	cout << "Old Board" << endl;
	print_board(board); 

	int step = 0;

	while (!is_solved(board))
	{
		vector<vector<vector<int>>> x = calculate_possibilities(board);

		vector<vector<int>> y = calculate_certainties(x);

		vector<vector<int>> z = fill_certainties(board, y);

		step++;

		cout << "step " << step << endl;

		if (z == board)
		{
			cout << "darn it" << endl;

			break;
		}

		board = z;

		print_board(board);
	}

	return 0;
}


