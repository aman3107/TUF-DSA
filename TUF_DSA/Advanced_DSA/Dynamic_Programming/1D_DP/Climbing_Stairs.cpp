#include <bits/stdc++.h>
using namespace std;

int climbStairs_Space(int n)
{
  int prev1 = 1;
  int prev2 = 1;
  for (int i = 2; i <= n; i++)
  {
    int curr_i = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr_i;
  }
  return prev1;
}

int climbStairsTabu(int n)
{
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int climbStairsMemo(int n, vector<int> &dp)
{
  if (n <= 1)
  {
    return 1;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}

int climbStairs(int n)
{
  if (n <= 1)
  {
    return 1;
  }
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << climbStairs_Space(n) << endl;
  cout << climbStairsTabu(n) << endl;
  cout << climbStairsMemo(n, dp) << endl;
  cout << climbStairs(n) << endl;
}