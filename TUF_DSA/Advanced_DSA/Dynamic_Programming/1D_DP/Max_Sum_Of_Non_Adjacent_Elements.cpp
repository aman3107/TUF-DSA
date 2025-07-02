#include <bits/stdc++.h>
using namespace std;

int nonAdjacentSpace(vector<int> &nums)
{
  int n = nums.size();
  int prev1 = nums[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int pick = nums[i];
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

int nonAdjacentTabu(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n, 0);
  dp[0] = nums[0];
  for (int i = 1; i < n; i++)
  {
    int pick = nums[i];
    if (i > 1)
    {
      pick += dp[i - 2];
    }
    int notPick = dp[i - 1];
    dp[i] = max(pick, notPick);
  }
  return dp[n - 1];
}

int memoHelper(vector<int> &nums, int ind, vector<int> &dp)
{
  if (ind == 0)
    return nums[ind];
  if (ind < 0)
    return 0;
  if (dp[ind] != -1)
  {
    return dp[ind];
  }
  int pick = nums[ind] + memoHelper(nums, ind - 2, dp);
  int notPick = memoHelper(nums, ind - 1, dp);
  return max(pick, notPick);
}

int nonAdjacentMemo(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n, -1);
  return memoHelper(nums, n - 1, dp);
}

int helper(vector<int> &nums, int ind)
{
  if (ind == 0)
    return nums[ind];
  if (ind < 0)
    return 0;

  int pick = nums[ind] + helper(nums, ind - 2);
  int notPick = helper(nums, ind - 1);
  return max(pick, notPick);
}

int nonAdjacent(vector<int> &nums)
{
  int n = nums.size();
  return helper(nums, n - 1);
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
  cout << nonAdjacentTabu(arr) << endl;
  cout << nonAdjacentMemo(arr) << endl;
  cout << nonAdjacent(arr) << endl;
}