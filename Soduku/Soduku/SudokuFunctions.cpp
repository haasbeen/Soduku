#include<iostream>
#include<vector>
#include <string>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <stdlib.h>
#include "sudokuFunctions.h"
using namespace std;

vector<vector<int>> generate_board() {

	return

	{
		{ 8, 0, 0,	 9, 0, 2,	 6, 0, 3 },
		{ 1, 2, 4,	 8, 0, 3,	 0, 0, 0 },
		{ 6, 0, 0,	 0, 4, 0,	 8, 1, 0 },

		{ 7, 0, 1,	 6, 0, 0,	 0, 0, 9 },
		{ 3, 0, 8,	 0, 0, 0,	 4, 0, 7 },
		{ 0, 0, 0,	 4, 0, 9,	 0, 3, 8 },

		{ 0, 8, 0,	 2, 0, 0,	 0, 7, 0 },
		{ 0, 0, 3,	 0, 8, 6,	 0, 5, 4 },
		{ 0, 7, 2,	 0, 5, 0,	 0, 8, 0 },
	};
}

vector<vector<int>> parse_board(string web_board) {

	vector<int> web_row;
	vector<vector<int>> new_board;
	

	for (int i = 0; i < web_board.size(); i++) {
		web_row.push_back(stoi(string(1, web_board[i])));

		if ((i + 1) % 9 == 0 ) {
			new_board.push_back(web_row);
			web_row.clear();
			
		}
	}

	return new_board;
}

void print_board(vector<vector<int>> board) {


	for (int row_index = 0; row_index < 9; row_index++) {

		for (int column_index = 0; column_index < 9; column_index++) {

			cout << board[row_index][column_index] << "  ";

			if ((column_index + 1) % 3 == 0) {

				cout << "  ";
			}
		}
		cout << "\n";

		if ((row_index + 1) % 3 == 0) {

			cout << "\n";
		}
	}

}

vector<int> row(vector<vector<int>> board, int row_index) {
	return board[row_index];
}

vector<int> column(vector<vector<int>> board, int column_index) {

	vector<int> call_column;

	for (int row_index = 0; row_index < 9; row_index++) {
		call_column.push_back(board[row_index][column_index]);
	}
	return call_column;
}

vector <int> subtract(vector <int> A, vector <int> B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> C;
	set_difference(
		A.begin(), A.end(),
		B.begin(), B.end(),
		back_inserter(C)
	);
	return C;
}

vector<vector<vector<int>>> calculate_possibilities(vector<vector<int>> board) {
	vector<vector<vector<int>>> board_possibilites = 
	{
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },

		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },

		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
		{ {}  , {}  ,  {}  ,   {}  ,  {}  ,  {}  ,   {}  ,  {}  ,  {}  },
	};
	for (int row_index = 0; row_index < 9; row_index++)
	{
		for (int column_index = 0; column_index < 9; column_index++) {
			if (board[row_index][column_index] != 0)
			{
				vector <int> blank; // Might need pushback
				board_possibilites[row_index][column_index] = blank;
				continue;
			}
			vector <int> r = row(board, row_index);
			vector <int> c = column(board, column_index);
			vector <int> b = box(board, row_index, column_index);

			vector <int> potential_numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			potential_numbers = subtract(potential_numbers, r);
			potential_numbers = subtract(potential_numbers, c);
			potential_numbers = subtract(potential_numbers, b);
			board_possibilites[row_index][column_index] = potential_numbers;
		}
	} 
	return board_possibilites;
}	

vector<vector<int>> calculate_certainties(vector<vector<vector<int>>> board_possibilities) {
	vector<vector<int>> board_certainties =
	{
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },

		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },

		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
	};
	for (int row_index = 0; row_index < 9; row_index++) {

		for (int column_index = 0; column_index < 9; column_index++) {
			if (board_possibilities[row_index][column_index].size() == 1)
			{
				board_certainties[row_index][column_index] = board_possibilities[row_index][column_index][0];
			}
		}
	}
	return board_certainties;
}

vector<vector<int>> fill_certainties(vector<vector<int>>board, vector<vector<int>> board_certainties) {
	vector<vector<int>> new_board =
	{
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },

		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },

		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
		{ 0  , 0  ,  0  ,   0  ,  0  ,  0  ,   0  ,  0  ,  0  },
	};
	for (int row_index = 0; row_index < 9; row_index++) {

		for (int column_index = 0; column_index < 9; column_index++) {
			if (board_certainties[row_index][column_index] != 0) {

				new_board[row_index][column_index] = board_certainties[row_index][column_index];
			}
			else
			{
				new_board[row_index][column_index] = board[row_index][column_index];
			}
		}
	}
	return new_board;
}
bool is_solved(vector<vector<int>> board) {
	for (int row_index = 0; row_index < 9; row_index++)
	{
		for (int column_index = 0; column_index < 9; column_index++) {

			if (board[row_index][column_index] == 0) {
				return false;
			}
		}
	}
	return true;
}

vector<int> box(vector<vector<int>>& board, int row_index, int column_index) {
	vector<int> box_numbers;
	int box_row = row_index / 3;
	int box_column = column_index / 3;
	int box_row_start = box_row * 3;
	int box_row_end = box_row_start + 3;
	int column_start = box_column * 3;
	int column_end = column_start + 3;
	for (int box_row_index = box_row_start; box_row_index < box_row_end; box_row_index++) {
		for (int box_column_index = column_start; box_column_index < column_end; box_column_index++) {
			box_numbers.push_back(board[box_row_index][box_column_index]);
		}
	}
	return box_numbers;
}

