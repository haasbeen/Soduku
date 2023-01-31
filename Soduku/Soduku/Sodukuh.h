#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>
#include <algorithm>
using namespace std; ma once


vector<vector<int>> generate_board();

void print_board(vector<vector<int>> board);

vector<int> row(vector<vector<int>> board, int row_index);

vector<int> column(vector<vector<int>> board, int column_index);

vector <int> substract(vector <int> A, vector <int> B);

int calculate_possibilities(vector<vector<int>> board);

bool is_solved(vector<vector<int>> board);

vector<int> box(vector<vector<int>>& board, int row_index, int column_index);
