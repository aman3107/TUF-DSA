#include <bits/stdc++.h>
using namespace std;

bool safe(vector<string> &board, int row, int col)
{
  int r = row, c = col;
  // Same row  check
  while (r >= 0)
  {
    if (board[r][c] == 'Q')
    {
      return false;
    }
    r--;
  }
  r = row;
  c = col;
  // right diagonal check
  while (r >= 0 && c < board.size())
  {
    if (board[r][c] == 'Q')
    {
      return false;
    }
    r--;
    c++;
  }
  r = row;
  c = col;

  // left diagonal check
  while (r >= 0 && c >= 0)
  {
    if (board[r][c] == 'Q')
    {
      return false;
    }
    r--;
    c--;
  }
  return true;
}

void solveNQueensHelper(int row, vector<vector<string>> &ans, vector<string> &board)
{
  if (row == board.size())
  {
    ans.push_back(board);
    return;
  }
  for (int col = 0; col < board.size(); col++)
  {
    if (safe(board, row, col))
    {
      board[row][col] = 'Q';
      solveNQueensHelper(row + 1, ans, board);
      board[row][col] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  // your code goes here
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  solveNQueensHelper(0, ans, board);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<string>> str = solveNQueens(n);
  for (auto s : str)
  {
    for (string el : s)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  return 0;
}