#include <bits/stdc++.h>
using namespace std;

bool areRulesMet(vector<vector<char>> &board, int row, int col, int digit)
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i][col] == digit || board[row][i] == digit)
    {
      return false;
    }
  }

  int startRow = (row / 3) * 3;
  int startCol = (col / 3) * 3;
  for (int i = startRow; i < startRow + 3; i++)
  {
    for (int j = startCol; j < startCol + 3; j++)
    {
      if (board[i][j] == digit)
      {
        return false;
      }
    }
  }
  return true;
}

bool solveSudokuSolver(vector<vector<char>> &board)
{
  int n = 9;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == '.')
      {
        for (char digit = '1'; digit <= '9'; digit++)
        {
          if (areRulesMet(board, i, j, digit))
          {
            board[i][j] = digit;
            bool val = solveSudokuSolver(board);
            if (val == true)
            {
              return true;
            }
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}

void solveSudoku(vector<vector<char>> &board)
{
  // your code goes here
  solveSudokuSolver(board);
}

int main()
{
  vector<vector<char>> board;
  for (int i = 0; i < 9; i++)
  {
    vector<char> temp;
    for (int j = 0; j < 9; j++)
    {
      char ch;
      cin >> ch;
      temp.push_back(ch);
    }
    board.push_back(temp);
  }
  solveSudoku(board);
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}