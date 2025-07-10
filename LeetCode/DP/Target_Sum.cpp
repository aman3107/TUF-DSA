#include <bits/stdc++.h>
using namespace std;

int countPartitionsSpace(int n, int diff, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  if ((totalSum - diff) < 0 || (totalSum - diff) % 2 == 1)
    return 0;
  int K = (totalSum - diff) / 2;
  vector<int> prev(K + 1, 0);
  vector<int> curr(K + 1, 0);
  int mod = 1e9 + 7;

  prev[0] = curr[0] = 1;
  if (arr[0] == 0)
  {
    prev[0] = 2;
  }
  if (arr[0] != 0 && arr[0] <= K)
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

int countPartitionsTabu(int n, int diff, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  if ((totalSum - diff) < 0 || (totalSum - diff) % 2 == 1)
    return 0;
  int K = (totalSum - diff) / 2;
  vector<vector<int>> dp(n, vector<int>(K + 1, 0));
  int mod = 1e9 + 7;
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (arr[0] == 0)
  {
    dp[0][0] = 2;
  }
  if (arr[0] != 0 && arr[0] <= K)
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

int helperMemo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (target == 0)
    return 1;
  if (ind == 0)
    return (arr[ind] == target);
  if (dp[ind][target] != -1)
  {
    return dp[ind][target];
  }
  int mod = 1e9 + 7;
  int take = 0;
  if (target >= arr[ind])
  {
    take = helperMemo(ind - 1, target - arr[ind], arr, dp);
  }
  int notTake = helperMemo(ind - 1, target, arr, dp);
  return dp[ind][target] = (take + notTake) % mod;
}

int countPartitionsMemo(int n, int diff, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  if ((totalSum - diff) < 0 || (totalSum - diff) % 2 == 1)
    return 0;
  int K = (totalSum - diff) / 2;
  vector<vector<int>> dp(n, vector<int>(K + 1, -1));
  return helperMemo(n - 1, K, arr, dp);
}

int helperRecur(int ind, int target, vector<int> &arr)
{
  if (target == 0)
    return 1;
  if (ind == 0)
    return (arr[ind] == target);

  int take = 0;
  if (target >= arr[ind])
  {
    take = helperRecur(ind - 1, target - arr[ind], arr);
  }
  int notTake = helperRecur(ind - 1, target, arr);
  return take + notTake;
}

int countPartitions(int n, int diff, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  if ((totalSum - diff) < 0 || (totalSum - diff) % 2 == 1)
    return 0;
  int K = (totalSum - diff) / 2;
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
  cout << "enter value of diff" << endl;
  int diff;
  cin >> diff;
  cout << countPartitions(n, diff, arr) << endl;
}