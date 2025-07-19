#include <bits/stdc++.h>
using namespace std;

/*
Intuition
🎯 Problem Summary
Given an array nums, where each element represents a balloon with a number, you can burst a balloon i to earn:
coins = nums[i-1] * nums[i] * nums[i+1]
After bursting a balloon, it disappears, and its neighbors become adjacent.
Your goal is to burst all the balloons in an order that maximizes the total coins collected.

🧠 Intuition
❗ Problem with direct bursting
If you try to simulate the bursting process directly, the array keeps shrinking and the values of i-1 and i+1 keep changing. That makes it hard to plan ahead.

✅ Better Way: Think in reverse
Instead of thinking which balloon to burst first, think:
Which balloon should be the last to burst in a given range?
Why is this better?
When a balloon is the last to burst in a subrange [i..j], the boundaries nums[i-1] and nums[j+1] are fixed.
The cost of bursting that balloon is:
nums[i-1] * nums[ind] * nums[j+1]
This transforms the problem into a clean interval DP problem.

Approach
1️⃣ Preprocess the array
Add 1 at the start and end of the array: nums = [1] + nums + [1]
This helps avoid edge cases for left and right multipliers.

2️⃣ DP Table Definition
Let dp[i][j] be the maximum coins you can collect by bursting all balloons between index i and j (both inclusive).

3️⃣ Filling Order
We loop i from n down to 1
We loop j from i up to n
This ensures that smaller intervals are computed before larger ones.

4️⃣ Transition
For each interval [i..j], we try bursting every possible balloon ind as the last balloon in that interval:
cost = nums[i-1] * nums[ind] * nums[j+1] // bursting ind last
+ dp[i][ind - 1] // coins from left
+ dp[ind + 1][j]; // coins from right
We take the maximum of all such possibilities:
dp[i][j] = max(dp[i][j], cost);
*/

int maxCoinsTabu(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
  for (int i = n; i >= 1; i--)
  {
    for (int j = i; j <= n; j++)
    {
      int maxi = 0;
      for (int ind = i; ind <= j; ind++)
      {
        int cost = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
        maxi = max(maxi, cost);
      }
      dp[i][j] = maxi;
    }
  }
  return dp[1][n];
}

int helperMemo(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int maxi = 0;
  for (int ind = i; ind <= j; ind++)
  {
    int cost = nums[i - 1] * nums[ind] * nums[j + 1] + helperMemo(i, ind - 1, nums, dp) + helperMemo(ind + 1, j, nums, dp);
    maxi = max(maxi, cost);
  }
  return dp[i][j] = maxi;
}

int maxCoinsMemo(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return helperMemo(1, n, nums, dp);
}

int helperRecur(int i, int j, vector<int> &nums)
{
  if (i > j)
    return 0;
  int maxi = 0;
  for (int ind = i; ind <= j; ind++)
  {
    int cost = nums[i - 1] * nums[ind] * nums[j + 1] + helperRecur(i, ind - 1, nums) + helperRecur(ind + 1, j, nums);
    maxi = max(maxi, cost);
  }
  return maxi;
}

int maxCoins(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  return helperRecur(1, n, nums);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums.push_back(data);
  }
  cout << maxCoinsMemo(nums) << endl;
  cout << maxCoins(nums) << endl;
}