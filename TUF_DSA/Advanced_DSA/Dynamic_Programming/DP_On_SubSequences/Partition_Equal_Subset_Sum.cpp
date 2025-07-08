#include <bits/stdc++.h>
using namespace std;

bool equalPartitionSpace(int n, vector<int> &arr)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 == 1)
  {
    return false;
  }

  int target = sum / 2;
  vector<int> prev(target + 1, 0);
  vector<int> curr(target + 1, 0);
  prev[0] = curr[0] = 0;
  if (arr[0] <= target)
  {
    prev[arr[0]] = 1;
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int i = 1; i <= target; i++)
    {
      bool take = false;
      if (i >= arr[ind])
      {
        take = prev[i - arr[ind]];
      }
      bool notTake = prev[i];
      curr[i] = take || notTake;
    }
    prev = curr;
  }
  return prev[target];
}

bool equalPartitionTabu(int n, vector<int> &arr)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 == 1)
  {
    return false;
  }

  int target = sum / 2;
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (arr[0] <= target)
    dp[0][arr[0]] = 1;

  for (int ind = 1; ind < n; ind++)
  {
    for (int i = 1; i <= target; i++)
    {
      bool take = false;
      if (i >= arr[ind])
      {
        take = dp[ind - 1][i - arr[ind]];
      }
      bool notTake = dp[ind - 1][i];
      dp[ind][i] = take || notTake;
    }
  }
  return dp[n - 1][target];
}

bool helperMemo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (target == 0)
    return true;
  if (ind == 0)
  {
    return (arr[0] == target);
  }

  if (dp[ind][target] != -1)
  {
    return dp[ind][target];
  }
  bool take = false;
  if (target >= arr[ind])
  {
    take = helperMemo(ind - 1, target - arr[ind], arr, dp);
  }
  bool notTake = helperMemo(ind - 1, target, arr, dp);
  return dp[ind][target] = take || notTake;
}

bool equalPartitionMemo(int n, vector<int> &arr)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 == 1)
  {
    return false;
  }

  int target = sum / 2;
  vector<vector<int>> dp(n, vector<int>(target + 1, -1));
  return helperMemo(n - 1, target, arr, dp);
}

bool helperRecur(int ind, int target, vector<int> &arr)
{
  if (target == 0)
    return true;
  if (ind == 0)
    return (arr[ind] == target);
  bool take = false;
  if (target >= arr[ind])
  {
    take = helperRecur(ind - 1, target - arr[ind], arr);
  }
  bool notTake = helperRecur(ind - 1, target, arr);
  return take || notTake;
}

bool equalPartition(int n, vector<int> arr)
{
  int sum = 0;
  // Count the total Sum
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  // If sum is odd then we can not divide the arr in two halves
  if (sum % 2 == 1)
  {
    return false;
  }
  // If S is even, then we need to find a subset in the input array whose sum is equal to S/2 because if we find one subset with sum S/2, the remaining elements sum will be automatically S/2.
  int target = sum / 2;
  return helperRecur(n - 1, target, arr);
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
  cout << equalPartitionTabu(n, arr) << endl;
  cout << equalPartitionMemo(n, arr) << endl;
  cout << equalPartition(n, arr) << endl;
}