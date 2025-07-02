#include <bits/stdc++.h>
using namespace std;

int spaceHelper(vector<int> &money)
{
  int n = money.size();
  int prev1 = money[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int pick = money[i];
    if (i > 1)
    {
      pick += prev2;
    }
    int notPick = prev1;
    int curr_i = max(pick, notPick);
    prev2 = prev1;
    prev1 = curr_i;
  }
  return prev1;
}

int houseRobberSpace(vector<int> &money)
{
  vector<int> arr1;
  vector<int> arr2;
  int n = money.size();
  if (n == 1)
    return money[0];
  for (int i = 0; i < money.size(); i++)
  {
    if (i != n - 1)
    {
      arr1.push_back(money[i]);
    }
    if (i != 0)
    {
      arr2.push_back(money[i]);
    }
  }
  int ans1 = spaceHelper(arr1);
  int ans2 = spaceHelper(arr2);
  return max(ans1, ans2);
}

int helperTabu(vector<int> &money)
{
  int n = money.size();
  vector<int> dp(n, 0);
  dp[0] = money[0];
  for (int i = 1; i < n; i++)
  {
    int pick = money[i];
    if (i > 1)
    {
      pick += dp[i - 2];
    }
    int notPick = dp[i - 1];
    dp[i] = max(pick, notPick);
  }
  return dp[n - 1];
}

int houseRobberTabu(vector<int> &money)
{
  vector<int> arr1;
  vector<int> arr2;
  int n = money.size();
  if (n == 1)
    return money[0];
  for (int i = 0; i < money.size(); i++)
  {
    if (i != n - 1)
    {
      arr1.push_back(money[i]);
    }
    if (i != 0)
    {
      arr2.push_back(money[i]);
    }
  }
  int ans1 = helperTabu(arr1);
  int ans2 = helperTabu(arr2);
  return max(ans1, ans2);
}

int helperMemo(vector<int> &nums, int ind, vector<int> &dp)
{
  if (ind == 0)
    return nums[ind];
  if (ind < 0)
    return 0;
  if (dp[ind] != -1)
  {
    return dp[ind];
  }
  int pick = nums[ind] + helperMemo(nums, ind - 2, dp);
  int notPick = helperMemo(nums, ind - 1, dp);
  return max(pick, notPick);
}

int houseRobberMemo(vector<int> &money)
{
  vector<int> arr1;
  vector<int> arr2;
  int n = money.size();
  if (n == 1)
    return money[0];
  for (int i = 0; i < money.size(); i++)
  {
    if (i != n - 1)
    {
      arr1.push_back(money[i]);
    }
    if (i != 0)
    {
      arr2.push_back(money[i]);
    }
  }
  vector<int> dp(n, -1);
  int ans1 = helperMemo(arr1, arr1.size() - 1, dp);
  int ans2 = helperMemo(arr2, arr2.size() - 1, dp);
  return max(ans1, ans2);
}

int helper(vector<int> &money, int ind)
{
  if (ind == 0)
    return money[0];
  if (ind < 0)
    return 0;
  int pick = money[ind] + helper(money, ind - 2);
  int notPick = helper(money, ind - 1);
  return max(pick, notPick);
}

int houseRobber(vector<int> &money)
{
  vector<int> arr1;
  vector<int> arr2;
  int n = money.size();
  if (n == 1)
    return money[0];
  for (int i = 0; i < money.size(); i++)
  {
    if (i != n - 1)
    {
      arr1.push_back(money[i]);
    }
    if (i != 0)
    {
      arr2.push_back(money[i]);
    }
  }
  int ans1 = helper(arr1, arr1.size() - 1);
  int ans2 = helper(arr2, arr2.size() - 1);
  return max(ans1, ans2);
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
  cout << houseRobberSpace(arr) << endl;
  cout << houseRobberTabu(arr) << endl;
  cout << houseRobberMemo(arr) << endl;
  cout << houseRobber(arr) << endl;
}