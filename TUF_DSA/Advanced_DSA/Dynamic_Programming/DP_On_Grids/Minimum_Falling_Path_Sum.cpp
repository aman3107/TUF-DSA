#include <bits/stdc++.h>
using namespace std;

int minFallingPathSumSpace(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<int> dp(m, 0);
  for (int i = 0; i < m; i++)
  {
    dp[i] = matrix[0][i];
  }
  for (int i = 1; i < n; i++)
  {
    vector<int> temp(m, 0);
    for (int j = 0; j < m; j++)
    {
      int up = matrix[i][j] + dp[j];
      int up_right = INT_MAX;
      int up_left = INT_MAX;
      if (j < m - 1)
      {
        up_right = matrix[i][j] + dp[j + 1];
      }
      if (j > 0)
      {
        up_left = matrix[i][j] + dp[j - 1];
      }
      temp[j] = min(up, min(up_left, up_right));
    }
    dp = temp;
  }
  int mini = INT_MAX;
  for (int i = 0; i < m; i++)
  {
    mini = min(mini, dp[i]);
  }
  return mini;
}

int minFallingPathSumTabu(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

  for (int i = 0; i < m; i++)
  {
    dp[0][i] = matrix[0][i];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = matrix[i][j] + dp[i - 1][j];
      int up_right = INT_MAX;
      int up_left = INT_MAX;
      if (j < m - 1)
      {
        up_right = matrix[i][j] + dp[i - 1][j + 1];
      }
      if (j > 0)
      {
        up_left = matrix[i][j] + dp[i - 1][j - 1];
      }
      dp[i][j] = min(up, min(up_left, up_right));
    }
  }

  int mini = INT_MAX;
  for (int i = 0; i < m; i++)
  {
    mini = min(mini, dp[n - 1][i]);
  }
  return mini;
}

int helperMemo(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
  if (col < 0 || col >= arr[0].size())
  {
    return 1e9;
  }
  if (row == 0)
  {
    return dp[row][col] = arr[row][col];
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int up = arr[row][col] + helperMemo(row - 1, col, arr, dp);
  int up_right = arr[row][col] + helperMemo(row - 1, col + 1, arr, dp);
  int up_left = arr[row][col] + helperMemo(row - 1, col - 1, arr, dp);

  return dp[row][col] = min(up, min(up_right, up_left));
}

int minFallingPathSumMemo(vector<vector<int>> &matrix)
{
  int row = matrix.size();
  int col = matrix[0].size();
  vector<vector<int>> dp(row, vector<int>(col, -1));
  int mini = INT_MAX;
  for (int i = 0; i < col; i++)
  {
    int ans = helperMemo(row - 1, i, matrix, dp);
    mini = min(ans, mini);
  }
  return mini;
}

int helperRecur(int row, int col, vector<vector<int>> &arr)
{
  if (col < 0 || col >= arr[0].size())
    return 1e9;
  if (row == 0)
  {
    return arr[row][col];
  }

  int up = arr[row][col] + helperRecur(row - 1, col, arr);
  int up_right = arr[row][col] + helperRecur(row - 1, col + 1, arr);
  int up_left = arr[row][col] + helperRecur(row - 1, col - 1, arr);
  return min(up, min(up_right, up_left));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  int mini = INT_MAX;
  for (int i = 0; i < m; i++)
  {
    int ans = helperRecur(n - 1, i, matrix);
    mini = min(ans, mini);
  }
  return mini;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    arr.push_back(temp);
  }
  cout << minFallingPathSumSpace(arr) << endl;
  cout << minFallingPathSumTabu(arr) << endl;
  cout << minFallingPathSumMemo(arr) << endl;
  cout << minFallingPathSum(arr) << endl;
}