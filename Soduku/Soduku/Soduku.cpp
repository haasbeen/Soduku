#include<iostream>
#include<vector>
using namespace std;

/*
dont repeat numbers
	vert, horz, 3x3 cube
	1-9 in every 3x3 cube

*/


vector<vector<int>> generate_board() {

	int BLANK = 0;

	return {
	{ BLANK,   7  ,   2  ,     BLANK, BLANK,   4  ,        9  , BLANK, BLANK },
	{   3  , BLANK,   4  ,     BLANK,   8  ,   9  ,        1  , BLANK, BLANK },
	{   8  ,   1  ,   9  ,     BLANK, BLANK,   6  ,        2  ,   5  ,   4   },

	{   7  , BLANK,   1  ,     BLANK, BLANK, BLANK,		 BLANK,   9  ,   5   },
	{   9  , BLANK, BLANK,     BLANK, BLANK,   2  ,		 BLANK,   7  , BLANK },
	{ BLANK, BLANK, BLANK,       8  , BLANK,   7  ,      BLANK,   1  ,   2   },

	{   4  , BLANK,   5  ,     BLANK, BLANK,   1  ,        6  ,   2  , BLANK },
	{   2  ,   3  ,   7  ,     BLANK, BLANK, BLANK,        5  , BLANK,   1   },
	{ BLANK, BLANK, BLANK,     BLANK,   2  ,   5  ,        7  , BLANK, BLANK },
	};
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



vector<int> box(vector<vector<int>> board, int row_index, int column_index) {

	int location = row_index * column_index;





	vector<int> call_box;

	for (int row_index = 0; row_index < 3; row_index++) {

		for (int column_index = 0; column_index < 3; column_index++) {

			call_box.push_back(board[row_index][column_index]);
		}
	}
	return call_box;


}

int main() {

	vector<vector<int>> board = generate_board();
	print_board(board);


	vector<int> b = box(board, 1, 3);



	return 0;
}


