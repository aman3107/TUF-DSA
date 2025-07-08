#include <bits/stdc++.h>
using namespace std;

int perfectSumSpace(vector<int> &arr, int K)
{
  int n = arr.size();
  int mod = 1e9 + 7;
  vector<int> prev(K + 1, 0);
  vector<int> curr(K + 1, 0);
  prev[0] = 1;
  if (arr[0] == 0)
  {
    prev[0] = 2;
  }
  if (arr[0] <= K && arr[0] != 0)
  {
    prev[arr[0]] = 1;
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int target = 0; target <= K; target++)
    {
      int take = 0;
      if (target >= arr[ind])
      {
        take = prev[target - arr[ind]];
      }
      int notTake = prev[target];
      curr[target] = (take + notTake) % mod;
    }
    prev = curr;
  }
  return prev[K];
}

int perfectSumTabu(vector<int> &arr, int K)
{
  int n = arr.size();
  int mod;
  vector<vector<int>> dp(n, vector<int>(K + 1, 0));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (arr[0] == 0)
  {
    dp[0][0] = 2;
  }

  if (arr[0] <= K)
  {
    dp[0][arr[0]] = 1;
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int target = 0; target <= K; target++)
    {
      int take = 0;
      if (target >= arr[ind])
      {
        take = dp[ind - 1][target - arr[ind]];
      }
      int notTake = dp[ind - 1][target];
      dp[ind][target] = (take + notTake) % mod;
    }
  }
  return dp[n - 1][K];
}

int helperMemo(int ind, int k, vector<int> &arr, vector<vector<int>> &dp)
{
  if (k == 0)
    return 1;
  if (ind == 0)
  {
    if (arr[0] == k)
      return 1;
    return 0;
  }

  if (dp[ind][k] != -1)
  {
    return dp[ind][k];
  }
  int mod = 1e9 + 7;
  int pick = 0;
  if (k >= arr[ind])
  {
    pick = helperMemo(ind - 1, k - arr[ind], arr, dp);
  }
  int notPick = helperMemo(ind - 1, k, arr, dp);

  return dp[ind][k] = (pick + notPick) % mod;
}

int perfectSumMemo(vector<int> &arr, int K)
{
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(K + 1, -1));
  return helperMemo(n - 1, K, arr, dp);
}

int helperRecur(int ind, int k, vector<int> &arr)
{
  if (k == 0)
  {
    return 1;
  }
  if (ind == 0)
  {
    if (arr[0] == k)
      return 1;
    return 0;
  }
  int take = 0;
  if (k >= arr[ind])
  {
    take = helperRecur(ind - 1, k - arr[ind], arr);
  }
  int notTake = helperRecur(ind - 1, k, arr);
  return take + notTake;
}

int perfectSum(vector<int> &arr, int K)
{
  int n = arr.size();
  return helperRecur(n - 1, K, arr);
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
  cout << "enter value of K" << endl;
  int k;
  cin >> k;
  cout << perfectSumSpace(arr, k) << endl;
  cout << perfectSumTabu(arr, k) << endl;
  cout << perfectSumMemo(arr, k) << endl;
  cout << perfectSum(arr, k) << endl;
}