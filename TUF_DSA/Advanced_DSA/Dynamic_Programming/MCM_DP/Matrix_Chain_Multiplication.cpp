#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = 1; j < n; j++)
    {
      int mini = INT_MAX;
      for (int k = i; k < j; k++)
      {
        int steps = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j];
        mini = min(mini, steps);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][n - 1];
}

int matrixMultiplicationTabu(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = 1; j < n; j++)
    {
      int mini = INT_MAX;
      for (int k = i; k < j; k++)
      {
        int steps = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j];
        mini = min(mini, steps);
        dp[i][j] = mini;
      }
    }
  }
  return dp[1][n - 1];
}

int helperMemo(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
  if (i == j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int mini = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int steps = (nums[i - 1] * nums[k] * nums[j]) + helperMemo(i, k, nums, dp) + helperMemo(k + 1, j, nums, dp);
    mini = min(mini, steps);
  }
  return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return helperMemo(1, n - 1, nums, dp);
}

int helperRecur(int i, int j, vector<int> &nums)
{
  if (i == j)
    return 0;

  int mini = 1e9;
  for (int k = i; k < j; k++)
  {
    int steps = (nums[i - 1] * nums[k] * nums[j]) + helperRecur(i, k, nums) + helperRecur(k + 1, j, nums);
    mini = min(mini, steps);
  }
  return mini;
}

int matrixMultiplication(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  return helperRecur(1, n - 1, nums);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  cout << matrixMultiplication(arr) << endl;
}