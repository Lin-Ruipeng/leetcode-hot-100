// T51.N皇后

#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<vector<string>> result;
  // n是棋盘大小, row表示递归到第几行
  void backtracking(int n, int row, vector<string>& chessboard) {
    if (row == n) {
      result.push_back(chessboard);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (isValid(row, col, chessboard, n)) {
        chessboard[row][col] = 'Q';
        backtracking(n, row + 1, chessboard);
        chessboard[row][col] = '.';
      }
    }
  }
  bool isValid(int row, int col, vector<string>& chessboard, int n) {
    int count = 0;
    // 列检查 有剪枝
    for (int i = 0; i < row; ++i) {
      if (chessboard[i][col] == 'Q') {
        return false;
      }
    }
    // 检查左斜线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    // 检查右斜线
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    result.clear();
    std::vector<string> chessboard(n, string(n, '.'));
    backtracking(n, 0, chessboard);
    return result;
  }
};
