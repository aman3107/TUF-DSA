#include <bits/stdc++.h>
using namespace std;

int countSpace(vector<int> &coins, int N, int amount)
{
  vector<int> prev(amount + 1, 0);
  vector<int> curr(amount + 1, 0);
  for (int i = 0; i <= amount; i++)
  {
    if (i % coins[0] == 0)
      prev[i] = 1;
  }
  int mod = 1e9 + 7;
  for (int ind = 1; ind < N; ind++)
  {
    for (int target = 0; target <= amount; target++)
    {
      int take = 0;
      if (target >= coins[ind])
      {
        take = curr[target - coins[ind]];
      }
      int notTake = prev[target];
      curr[target] = (take + notTake) % mod;
    }
    prev = curr;
  }
  return prev[amount];
}

int countTabu(vector<int> &coins, int N, int amount)
{
  vector<vector<int>> dp(N, vector<int>(amount + 1, 0));
  for (int i = 0; i <= amount; i++)
  {
    if (i % coins[0] == 0)
      dp[0][i] = 1;
  }
  int mod = 1e9 + 7;
  for (int ind = 1; ind < N; ind++)
  {
    for (int target = 0; target <= amount; target++)
    {
      int take = 0;
      if (target >= coins[ind])
      {
        take = dp[ind][target - coins[ind]];
      }
      int notTake = dp[ind - 1][target];
      dp[ind][target] = (take + notTake) % mod;
    }
  }
  return dp[N - 1][amount];
}

int helperMemo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (target % arr[ind] == 0)
      return 1;
    return 0;
  }
  if (dp[ind][target] != -1)
  {
    return dp[ind][target];
  }
  int take = 0;
  if (target >= arr[ind])
  {
    take = helperMemo(ind, target - arr[ind], arr, dp);
  }
  int notTake = helperMemo(ind - 1, target, arr, dp);
  return dp[ind][target] = take + notTake;
}

int countMemo(vector<int> &coins, int N, int amount)
{
  vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
  return helperMemo(N - 1, amount, coins, dp);
}

int helperRecur(int ind, int tar, vector<int> &arr)
{
  if (ind == 0)
  {
    if (tar % arr[0] == 0)
      return 1;
    return 0;
  }
  int take = 0;
  if (tar >= arr[ind])
  {
    take = helperRecur(ind, tar - arr[ind], arr);
  }
  int notTake = helperRecur(ind - 1, tar, arr);
  return take + notTake;
}
int count(vector<int> &coins, int N, int amount)
{
  return helperRecur(N - 1, amount, coins);
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
  cout << "target value :" << endl;
  int tar;
  cin >> tar;
  cout << countSpace(arr, n, tar) << endl;
  cout << countTabu(arr, n, tar) << endl;
  cout << countMemo(arr, n, tar) << endl;
  // cout << count(arr, n, tar) << endl;
}