#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minScoreTriangulation(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
      for (int j = 1; j < n; j++)
      {
        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
          int steps = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j];
          mini = min(mini, steps);
          dp[i][j] = mini;
        }
      }
    }
    return dp[1][n - 1];
  }
};