#include <bits/stdc++.h>
using namespace std;

bool existHelper(int ind, int x, int y, vector<vector<char>> &board, int m, int n, string word)
{
  // your code goes here
  if (ind == word.size())
  {
    return true;
  }
  if (board[x][y] == '1' || board[x][y] != word[ind])
  {
    return false;
  }
  char ch = board[x][y];
  board[x][y] = '1';
  bool ans = false;
  if (x - 1 >= 0)
  {
    ans |= existHelper(ind + 1, x - 1, y, board, m, n, word);
  }
  if (x + 1 < m)
  {
    ans |= existHelper(ind + 1, x + 1, y, board, m, n, word);
  }
  if (y - 1 >= 0)
  {
    ans |= existHelper(ind + 1, x, y - 1, board, m, n, word);
  }
  if (y + 1 < n)
  {
    ans |= existHelper(ind + 1, x, y + 1, board, m, n, word);
  }
  board[x][y] = ch;
  return ans;
}

bool exist(vector<vector<char>> &board, string word)
{
  // your code goes here
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == word[0])
      {
        if (existHelper(0, i, j, board, m, n, word))
        {
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<char>> board;
  for (int i = 0; i < m; i++)
  {
    vector<char> temp;
    for (int j = 0; j < n; j++)
    {
      char ch;
      cin >> ch;
      temp.push_back(ch);
    }
    board.push_back(temp);
  }

  string word;
  cin >> word;
  cout << exist(board, word) << endl;
}