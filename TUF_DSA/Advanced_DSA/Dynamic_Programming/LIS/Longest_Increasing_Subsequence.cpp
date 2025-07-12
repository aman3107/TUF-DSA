#include <bits/stdc++.h>
using namespace std;

int LISTabuNew(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n, 1);
  int maxi = 1;
  for (int ind = 1; ind < n; ind++)
  {
    for (int prev_ind = 0; prev_ind < ind; prev_ind++)
    {
      if (nums[ind] > nums[prev_ind])
      {
        dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
      }
    }
    maxi = max(maxi, dp[ind]);
  }
  return maxi;
}

int LISspace(vector<int> &nums)
{
  int n = nums.size();
  vector<int> next(n + 1, 0), curr(n + 1, 0);
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
    {
      int take = 0;
      if (prev_ind == -1 || nums[ind] > nums[prev_ind])
      {
        take = 1 + next[ind];
      }
      int notTake = next[prev_ind + 1];
      curr[prev_ind + 1] = max(take, notTake);
    }
    next = curr;
  }
  return next[0];
}

int LISTabu(vector<int> &nums)
{
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
    {
      int take = 0;
      if (prev_ind == -1 || nums[ind] > nums[prev_ind])
      {
        take = 1 + dp[ind + 1][ind];
      }
      int notTake = dp[ind + 1][prev_ind + 1];
      dp[ind][prev_ind + 1] = max(take, notTake);
    }
  }
  return dp[0][0];
}

int helperMemo(int ind, int prev_ind, vector<int> &arr, vector<vector<int>> &dp)
{
  if (ind == arr.size())
  {
    return 0;
  }

  // Since array cannot be -1 index. So we will prev_ind as prev_ind+1. So that for -1 scenario it will be consider as 0
  if (dp[ind][prev_ind + 1] != -1)
  {
    return dp[ind][prev_ind + 1];
  }
  int take = 0;
  if (prev_ind == -1 || arr[ind] > arr[prev_ind])
  {
    take = 1 + helperMemo(ind + 1, ind, arr, dp);
  }
  int notTake = helperMemo(ind + 1, prev_ind, arr, dp);
  return dp[ind][prev_ind + 1] = max(take, notTake);
}

int LISMemo(vector<int> &nums)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return helperMemo(0, -1, nums, dp);
}

int helperRecur(int ind, int prev_ind, vector<int> &arr)
{
  if (ind == arr.size())
  {
    return 0;
  }
  int take = 0;
  if (prev_ind == -1 || arr[ind] > arr[prev_ind])
  {
    take = 1 + helperRecur(ind + 1, ind, arr);
  }
  int notTake = helperRecur(ind + 1, prev_ind, arr);
  return max(take, notTake);
}

int LIS(vector<int> &nums)
{
  return helperRecur(0, -1, nums);
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
  cout << LISMemo(arr) << endl;
  cout << LIS(arr) << endl;
}