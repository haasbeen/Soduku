#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>
#include <algorithm>
using namespace std;


vector<vector<int>> generate_board();

void print_board(vector<vector<int>> board);

vector<int> row(vector<vector<int>> board, int row_index);

vector<int> column(vector<vector<int>> board, int column_index);

vector <int> subtract(vector <int> A, vector <int> B);

vector<vector<vector<int>>> calculate_possibilities(vector<vector<int>> board);

vector<vector<int>> calculate_certainties(vector<vector<vector<int>>> board_possibilities);

vector<vector<int>> fill_certainties(vector<vector<int>>board, vector<vector<int>> board_certainties);

bool is_solved(vector<vector<int>> board);

vector<int> box(vector<vector<int>>& board, int row_index, int column_index);
