#include <bits/stdc++.h>
using namespace std;

int minDifferenceSpace(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  int k = totalSum;
  vector<bool> prev(totalSum + 1, false);
  vector<bool> curr(totalSum + 1, false);
  prev[0] = curr[0] = true;
  if (arr[0] <= k)
    prev[arr[0]] = true;
  for (int ind = 1; ind < n; ind++)
  {
    for (int target = 1; target <= k; target++)
    {
      bool take = false;
      if (target >= arr[ind])
      {
        take = prev[target - arr[ind]];
      }
      bool notTake = prev[target];
      curr[target] = take || notTake;
    }
    prev = curr;
  }

  int mini = 1e9;
  for (int i = 0; i <= totalSum / 2; i++)
  {
    if (prev[i] == true)
    {
      int s1 = i;
      int s2 = totalSum - i;
      mini = min(mini, abs(s1 - s2));
    }
  }
  return mini;
}

int minDifferenceTabu(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += arr[i];
  }
  int k = totalSum;
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  if (arr[0] <= k)
    dp[0][arr[0]] = true;
  for (int ind = 1; ind < n; ind++)
  {
    for (int target = 1; target <= k; target++)
    {
      bool take = false;
      if (target >= arr[ind])
      {
        take = dp[ind - 1][target - arr[ind]];
      }
      bool notTake = dp[ind - 1][target];
      dp[ind][target] = take || notTake;
    }
  }

  int mini = 1e9;
  for (int i = 0; i <= totalSum / 2; i++)
  {
    if (dp[n - 1][i] == true)
    {
      int s1 = i;
      int s2 = totalSum - i;
      mini = min(mini, abs(s1 - s2));
    }
  }
  return mini;
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
  cout << minDifferenceSpace(arr, n) << endl;
  cout << minDifferenceTabu(arr, n) << endl;
}