#include <bits/stdc++.h>
using namespace std;

int helperMemo(int row, int col1, int col2, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
{
  if (col1 < 0 || col2 < 0 || col1 >= arr[0].size() || col2 >= arr[0].size())
  {
    return -1e8;
  }
  if (row == arr.size() - 1)
  {
    if (col1 == col2)
    {
      return dp[row][col1][col2] = arr[row][col1];
    }
    else
    {
      return dp[row][col1][col2] = arr[row][col1] + arr[row][col2];
    }
  }
  if (dp[row][col1][col2] != -1)
  {
    return dp[row][col1][col2];
  }
  int maxi = 0;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (col1 == col2)
      {
        maxi = max(maxi, arr[row][col1] + helperMemo(row + 1, col1 + dj1, col2 + dj2, arr, dp));
      }
      else
      {
        maxi = max(maxi, arr[row][col1] + arr[row][col2] + helperMemo(row + 1, col1 + dj1, col2 + dj2, arr, dp));
      }
    }
  }
  return dp[row][col1][col2] = maxi;
}

int cherryPickupMemo(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
  return helperMemo(0, 0, m - 1, matrix, dp);
}

int helperRecur(int row, int col1, int col2, vector<vector<int>> &arr)
{
  if (col1 < 0 || col1 >= arr[0].size() || col2 < 0 || col2 >= arr[0].size())
  {
    return -1e8;
  }
  if (row == arr.size() - 1)
  {
    if (col1 == col2)
    {
      return arr[row][col1];
    }
    else
    {
      return arr[row][col1] + arr[row][col2];
    }
  }

  int maxi = 0;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (col1 == col2)
      {
        maxi = max(maxi, arr[row][col1] + helperRecur(row + 1, col1 + dj1, col2 + dj2, arr));
      }
      else
      {
        maxi = max(maxi, arr[row][col1] + arr[row][col2] + helperRecur(row + 1, col1 + dj1, col2 + dj2, arr));
      }
    }
  }
  return maxi;
}

int cherryPickup(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  return helperRecur(0, 0, m - 1, matrix);
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
  cout << cherryPickupMemo(arr) << endl;
  cout << cherryPickup(arr) << endl;
}