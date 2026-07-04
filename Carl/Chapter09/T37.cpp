// T37.解数独

#include <vector>

using namespace std;

class Solution {
  bool backtracking(vector<vector<char>>& board) {
    // 行
    for (int i = 0; i < board.size(); ++i) {
      // 列
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] != '.') continue;
        for (char k = '1'; k <= '9'; ++k) {
          if (isValid(i, j, k, board)) {
            board[i][j] = k;
            // 找到解
            if (backtracking(board)) return true;
            board[i][j] = '.';  // 回溯
          }
        }
        return false;  // 9个数字都用了
      }
    }
    return true;
  }
  bool isValid(int row, int col, char val, vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
      if (board[row][i] == val) {
        return false;
      }
    }
    for (int j = 0; j < board[0].size(); ++j) {
      if (board[j][col] == val) {
        return false;
      }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }

 public:
  void solveSudoku(vector<vector<char>>& board) { backtracking(board); }
};
