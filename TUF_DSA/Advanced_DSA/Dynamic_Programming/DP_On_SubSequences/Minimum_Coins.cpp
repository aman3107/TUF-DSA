#include <bits/stdc++.h>
using namespace std;

int MinimumCoinsSpace(vector<int> &coins, int amount)
{
  int n = coins.size();
  vector<int> prev(amount + 1, 1e9);
  vector<int> curr(amount + 1, 1e9);
  for (int i = 0; i <= amount; i++)
  {
    if (i % coins[0] == 0)
    {
      prev[i] = i / coins[0];
    }
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int tar = 0; tar <= amount; tar++)
    {
      int take = 1e9;
      if (tar >= coins[ind])
      {
        take = 1 + curr[tar - coins[ind]];
      }
      int notTake = prev[tar];
      curr[tar] = min(take, notTake);
    }
    prev = curr;
  }
  int ans = prev[amount];
  if (ans >= 1e9)
    return -1;
  return ans;
}

int MinimumCoinsTabu(vector<int> &coins, int amount)
{
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
  for (int i = 0; i <= amount; i++)
  {
    if (i % coins[0] == 0)
    {
      dp[0][i] = i / coins[0];
    }
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int tar = 0; tar <= amount; tar++)
    {
      int take = 1e9;
      if (tar >= coins[ind])
      {
        take = 1 + dp[ind][tar - coins[ind]];
      }
      int notTake = dp[ind - 1][tar];
      dp[ind][tar] = min(take, notTake);
    }
  }
  int ans = dp[n - 1][amount];
  if (ans >= 1e9)
    return -1;
  return ans;
}

int helperMemo(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (tar % arr[0] == 0)
      return tar / arr[0];
    return 1e9;
  }
  if (dp[ind][tar] != -1)
  {
    return dp[ind][tar];
  }
  int take = 1e9;
  if (tar >= arr[ind])
  {
    take = 1 + helperMemo(ind, tar - arr[ind], arr, dp);
  }
  int notTake = helperMemo(ind - 1, tar, arr, dp);
  return dp[ind][tar] = min(take, notTake);
}

int MinimumCoinsMemo(vector<int> &coins, int amount)
{
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  int ans = helperMemo(n - 1, amount, coins, dp);
  if (ans >= 1e9)
  {
    return -1;
  }
  return ans;
}

int helperRecur(int ind, int tar, vector<int> &arr)
{
  if (ind == 0)
  {
    if (tar % arr[0] == 0)
      return tar / arr[0];
    return 1e9;
  }

  int take = 1e9;
  if (tar >= arr[ind])
  {
    take = 1 + helperRecur(ind, tar - arr[ind], arr);
  }
  int notTake = helperRecur(ind - 1, tar, arr);
  return min(take, notTake);
}

int MinimumCoins(vector<int> &coins, int amount)
{
  int n = coins.size();
  int ans = helperRecur(n - 1, amount, coins);
  if (ans >= 1e9)
    return -1;
  return ans;
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
  cout << MinimumCoinsSpace(arr, tar) << endl;
  cout << MinimumCoinsTabu(arr, tar) << endl;
  cout << MinimumCoinsMemo(arr, tar) << endl;
  cout << MinimumCoins(arr, tar) << endl;
}