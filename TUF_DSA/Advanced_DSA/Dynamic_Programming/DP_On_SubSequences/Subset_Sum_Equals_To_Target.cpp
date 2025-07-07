#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumSpace(vector<int> &arr, int target)
{
  int n = arr.size();
  vector<int> prev(target + 1, 0);
  vector<int> curr(target + 1, 0);
  prev[0] = curr[0] = 1;
  if (arr[0] <= target)
    prev[arr[0]] = 1;
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

bool isSubsetSumTabu(vector<int> &arr, int target)
{
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
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
    return (arr[ind] == target);
  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool take = false;
  if (target >= arr[ind])
  {
    take = helperMemo(ind - 1, target - arr[ind], arr, dp);
  }
  bool notTake = helperMemo(ind - 1, target, arr, dp);
  return dp[ind][target] = take || notTake;
}

bool isSubsetSumMemo(vector<int> &arr, int target)
{
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
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
    take = helperRecur(ind - 1, target - arr[ind], arr);
  bool notTake = helperRecur(ind - 1, target, arr);
  return take || notTake;
}

bool isSubsetSum(vector<int> arr, int target)
{
  int n = arr.size();
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
  cout << "Enter target :" << endl;
  int target;
  cin >> target;
  cout << isSubsetSumSpace(arr, target) << endl;
  cout << isSubsetSumTabu(arr, target) << endl;
  cout << isSubsetSumMemo(arr, target) << endl;
  cout << isSubsetSum(arr, target) << endl;
}