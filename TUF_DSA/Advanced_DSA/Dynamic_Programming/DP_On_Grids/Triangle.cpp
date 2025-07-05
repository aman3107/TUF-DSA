#include <bits/stdc++.h>
using namespace std;

int minTriangleSpace(vector<vector<int>> &triangle)
{
  int n = triangle.size();
  vector<int> dp(n, 0);
  dp[0] = triangle[0][0];
  for (int i = 1; i < n; i++)
  {
    vector<int> temp(i + 1, 0);
    for (int j = 0; j <= i; j++)
    {
      int up = INT_MAX;
      int up_left = INT_MAX;
      if (j < i)
      {
        up = triangle[i][j] + dp[j];
      }
      if (j > 0)
      {
        up_left = triangle[i][j] + dp[j - 1];
      }
      temp[j] = min(up, up_left);
    }
    dp = temp;
  }
  int mini = INT_MAX;
  for (int i = 0; i < triangle[n - 1].size(); i++)
  {
    mini = min(mini, dp[i]);
  }
  return mini;
}

int minTriangleSumTabu(vector<vector<int>> &triangle)
{
  int n = triangle.size();
  vector<vector<int>> dp;
  for (int i = 0; i < n; i++)
  {
    int m = triangle[i].size();
    vector<int> temp(m, 1e9);
    dp.push_back(temp);
  }

  dp[0][0] = triangle[0][0];
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < triangle[i].size(); j++)
    {
      int up = INT_MAX;
      if (j < triangle[i - 1].size())
        up = triangle[i][j] + dp[i - 1][j];
      int up_left = 1e9;
      if (j > 0)
      {
        up_left = triangle[i][j] + dp[i - 1][j - 1];
      }
      dp[i][j] = min(up, up_left);
    }
  }
  int mini = INT_MAX;
  for (int i = 0; i < triangle[n - 1].size(); i++)
  {
    mini = min(mini, dp[n - 1][i]);
  }
  return mini;
}

int helperMemo(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
  if (col < 0 || col >= arr[row].size())
  {
    return 1e9;
  }
  if (row == 0 && col == 0)
  {
    return dp[row][col] = arr[row][col];
  }
  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }
  int up = arr[row][col] + helperMemo(row - 1, col, arr, dp);
  int up_left = arr[row][col] + helperMemo(row - 1, col - 1, arr, dp);
  return dp[row][col] = min(up, up_left);
}

int minTriangleSumMemo(vector<vector<int>> &triangle)
{
  int n = triangle.size();
  vector<vector<int>> dp;
  for (int i = 0; i < n; i++)
  {
    int m = triangle[i].size();
    vector<int> temp(m, -1);
    dp.push_back(temp);
  }
  int mini = INT_MAX;
  for (int i = 0; i < triangle[n - 1].size(); i++)
  {
    int ans = helperMemo(n - 1, i, triangle, dp);
    mini = min(mini, ans);
  }
  return mini;
}

int helperRecur(int row, int col, vector<vector<int>> &arr)
{
  if (row < 0 || col < 0 || col >= arr[row].size())
  {
    return 1e9;
  }
  if (row == 0 && col == 0)
  {
    return arr[row][col];
  }
  int up = arr[row][col] + helperRecur(row - 1, col, arr);
  int up_left = arr[row][col] + helperRecur(row - 1, col - 1, arr);
  return min(up, up_left);
}

int minTriangleSum(vector<vector<int>> &triangle)
{
  int n = triangle.size();
  int m = triangle[n - 1].size();
  int mini = INT_MAX;
  for (int i = 0; i < m; i++)
  {
    int ans = helperRecur(n - 1, i, triangle);
    mini = min(ans, mini);
  }
  return mini;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> triangle;
  for (int i = 0; i < n; i++)
  {
    int m;
    cout << "Enter column :" << endl;
    cin >> m;
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    triangle.push_back(temp);
  }
  cout << minTriangleSpace(triangle) << endl;
  cout << minTriangleSumTabu(triangle) << endl;
  cout << minTriangleSumMemo(triangle) << endl;
  cout << minTriangleSum(triangle) << endl;
}