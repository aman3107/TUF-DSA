#include <bits/stdc++.h>
using namespace std;

int targetSumSpace(int n, int target, vector<int> &nums)
{
  int totalSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalSum += nums[i];
  }
  if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
    return 0;
  int k = (totalSum - target) / 2;
  vector<int> prev(k + 1, 0);
  vector<int> curr(k + 1, 0);

  for (int i = 0; i < n; i++)
  {
    prev[0] = 1;
  }
  if (nums[0] == 0)
  {
    prev[0] = 2;
  }
  if (nums[0] != 0 && nums[0] <= k)
  {
    prev[nums[0]] = 1;
  }
  int mod = 1e9 + 7;

  for (int ind = 1; ind < n; ind++)
  {
    for (int tar = 0; tar <= k; tar++)
    {
      int take = 0;
      if (tar >= nums[ind])
      {
        take = prev[tar - nums[ind]];
      }
      int notTake = prev[tar];
      curr[tar] = (take + notTake) % mod;
    }
    prev = curr;
  }
  return prev[k];
}

int targetSumTabu(int n, int target, vector<int> &nums)
{
  int totalSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalSum += nums[i];
  }
  if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
    return 0;
  int k = (totalSum - target) / 2;
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (nums[0] == 0)
  {
    dp[0][0] = 2;
  }
  if (nums[0] != 0 && nums[0] <= k)
  {
    dp[0][nums[0]] = 1;
  }
  int mod = 1e9 + 7;

  for (int ind = 1; ind < n; ind++)
  {
    for (int tar = 0; tar <= k; tar++)
    {
      int take = 0;
      if (tar >= nums[ind])
      {
        take = dp[ind - 1][tar - nums[ind]];
      }
      int notTake = dp[ind - 1][tar];
      dp[ind][tar] = (take + notTake) % mod;
    }
  }
  return dp[n - 1][k];
}

int helperMemo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (target == 0)
  {
    return 1;
  }
  if (ind == 0)
  {
    if (target == arr[0])
    {
      return 1;
    }
    return 0;
  }

  if (dp[ind][target] != -1)
  {
    return dp[ind][target];
  }
  int take = 0;
  if (target >= arr[ind])
  {
    take = helperMemo(ind - 1, target - arr[ind], arr, dp);
  }
  int notTake = helperMemo(ind - 1, target, arr, dp);
  return dp[ind][target] = take + notTake;
}

int targetSumMemo(int n, int target, vector<int> &nums)
{
  int totalSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalSum += nums[i];
  }
  if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
    return 0;
  int k = (totalSum - target) / 2;
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return helperMemo(n - 1, k, nums, dp);
}

int helperRecur(int ind, int target, vector<int> &arr)
{
  if (target == 0)
  {
    return 1;
  }
  if (ind == 0)
  {
    if (target == arr[0])
    {
      return 1;
    }
    return 0;
  }
  int take = 0;
  if (target >= arr[ind])
  {
    take = helperRecur(ind - 1, target - arr[ind], arr);
  }
  int notTake = helperRecur(ind - 1, target, arr);
  return take + notTake;
}

int targetSum(int n, int target, vector<int> &nums)
{
  int totalSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalSum += nums[i];
  }
  if ((totalSum - target) < 0 || (totalSum - target) % 2 == 1)
    return 0;
  int k = (totalSum - target) / 2;
  return helperRecur(n - 1, k, nums);
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
  cout << "enter value" << endl;
  int tar;
  cin >> tar;
  cout << targetSumMemo(n, tar, arr) << endl;
  cout << targetSum(n, tar, arr) << endl;
}