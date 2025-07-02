#include <bits/stdc++.h>
using namespace std;

int frogJumpSpace(vector<int> &heights)
{
  int n = heights.size();
  int prev2 = 0;
  int prev = abs(heights[0] - heights[1]);
  for (int i = 2; i < n; i++)
  {
    int oneStep = prev + abs(heights[i] - heights[i - 1]);
    int twoStep = prev2 + abs(heights[i] - heights[i - 2]);
    int curr_i = min(oneStep, twoStep);
    prev2 = prev;
    prev = curr_i;
  }
  return prev;
}

int frogJumpTabu(vector<int> &heights)
{
  int n = heights.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = abs(heights[1] - heights[0]);
  for (int i = 2; i < n; i++)
  {
    int oneStep = abs(heights[i] - heights[i - 1]) + dp[i - 1];
    int twoStep = abs(heights[i] - heights[i - 2]) + dp[i - 2];
    dp[i] = min(oneStep, twoStep);
  }
  return dp[n - 1];
}

int frogJumpMemoHelper(vector<int> &heights, vector<int> &dp, int ind)
{
  if (ind == 0)
  {
    return 0;
  }
  if (ind < 0)
  {
    return INT_MAX;
  }
  if (dp[ind] != -1)
  {
    return dp[ind];
  }
  int oneStep = abs(heights[ind] - heights[ind - 1]) + frogJumpMemoHelper(heights, dp, ind - 1);
  int twoStep = INT_MAX;
  if (ind > 1)
  {
    twoStep = abs(heights[ind] - heights[ind - 2]) + frogJumpMemoHelper(heights, dp, ind - 2);
  }
  return dp[ind] = min(oneStep, twoStep);
}

int frogJumpMemo(vector<int> &heights)
{
  int n = heights.size();
  vector<int> dp(n + 1, -1);
  return frogJumpMemoHelper(heights, dp, n - 1);
}

int frogJumpHelper(vector<int> &heights, int ind)
{

  if (ind == 0)
  {
    return 0;
  }
  if (ind < 0)
  {
    return INT_MAX;
  }
  int twoStep = INT_MAX;
  int oneStep = abs(heights[ind] - heights[ind - 1]) + frogJumpHelper(heights, ind - 1);
  if (ind > 1)
  {
    twoStep = abs(heights[ind] - heights[ind - 2]) + frogJumpHelper(heights, ind - 2);
  }
  return min(oneStep, twoStep);
}

int frogJump(vector<int> &heights)
{
  return frogJumpHelper(heights, heights.size() - 1);
}

int main()
{
  int n;
  cin >> n;
  vector<int> heights;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    heights.push_back(data);
  }

  cout << frogJumpSpace(heights) << endl;
  cout << frogJumpTabu(heights) << endl;
  cout << frogJumpMemo(heights) << endl;
  cout << frogJump(heights) << endl;
}