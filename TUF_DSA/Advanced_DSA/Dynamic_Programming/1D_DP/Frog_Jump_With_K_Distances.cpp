#include <bits/stdc++.h>
using namespace std;

int frogJumpTabu(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> dp(n, 0);
  for (int i = 1; i < n; i++)
  {
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
        minSteps = min(minSteps, jump);
      }
      dp[i] = minSteps;
    }
  }
  return dp[n - 1];
}

int memoHelper(vector<int> &arr, int ind, int k, vector<int> &dp)
{
  if (ind == 0)
  {
    return 0;
  }
  if (ind < 0)
  {
    return INT_MAX;
  }
  if (dp[ind] != -1)
  {
    return dp[ind];
  }
  int minValue = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if (ind - i >= 0)
    {
      int step = abs(arr[ind] - arr[ind - i]) + memoHelper(arr, ind - i, k, dp);
      minValue = min(minValue, step);
    }
  }
  return dp[ind] = minValue;
}

int frogJumpMemo(vector<int> &heights, int k)
{
  int n = heights.size();
  vector<int> dp(n + 1, -1);
  return memoHelper(heights, n - 1, k, dp);
}

int helper(vector<int> &arr, int ind, int k)
{
  if (ind == 0)
  {
    return 0;
  }
  if (ind < 0)
  {
    return INT_MAX;
  }
  int minValue = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if (ind - i >= 0)
    {
      int step = abs(arr[ind] - arr[ind - i]) + helper(arr, ind - i, k);
      minValue = min(minValue, step);
    }
  }
  return minValue;
}

int frogJump(vector<int> &heights, int k)
{
  int n = heights.size();
  return helper(heights, n - 1, k);
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
  int k;
  cin >> k;
  cout << frogJumpTabu(arr, k) << endl;
  cout << frogJumpMemo(arr, k) << endl;
  cout << frogJump(arr, k) << endl;
}