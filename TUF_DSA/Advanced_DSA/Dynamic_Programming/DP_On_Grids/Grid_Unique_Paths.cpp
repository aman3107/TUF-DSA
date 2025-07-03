#include <bits/stdc++.h>
using namespace std;

int uniquePathsTabu(int row, int col)
{
  vector<vector<int>> dp(row, vector<int>(col, 0));
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      int up = 0;
      int left = 0;
      if (i > 0)
      {
        up = dp[i - 1][j];
      }
      if (j > 0)
      {
        left = dp[i][j - 1];
      }
      dp[i][j] = up + left;
    }
  }
  return dp[row - 1][col - 1];
}

int helperMemo(int row, int col, vector<vector<int>> &dp)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }
  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }
  int right = helperMemo(row, col - 1, dp);
  int bottom = helperMemo(row - 1, col, dp);
  return dp[row][col] = right + bottom;
}

int uniquePathsMemo(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return helperMemo(m - 1, n - 1, dp);
}

int helperRecur(int row, int col)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }

  int right = helperRecur(row, col - 1);
  int bottom = helperRecur(row - 1, col);
  return right + bottom;
}

int uniquePaths(int m, int n)
{
  return helperRecur(m - 1, n - 1);
}

int main()
{
  int m, n;
  cin >> m >> n;
  cout << uniquePathsMemo(m, n) << endl;
  cout << uniquePaths(m, n) << endl;
}