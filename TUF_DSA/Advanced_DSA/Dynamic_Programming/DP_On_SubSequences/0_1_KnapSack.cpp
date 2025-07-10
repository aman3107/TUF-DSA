#include <bits/stdc++.h>
using namespace std;

int knapsack01Space(vector<int> &wt, vector<int> &val, int n, int W)
{
  vector<int> prev(W + 1, 0);
  vector<int> curr(W + 1, 0);
  for (int i = wt[0]; i <= W; i++)
  {
    prev[i] = val[0];
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int Wt = 0; Wt <= W; Wt++)
    {
      int take = 0;
      if (Wt >= wt[ind])
      {
        take = val[ind] + prev[Wt - wt[ind]];
      }
      int notTake = prev[Wt];
      prev[Wt] = max(take, notTake);
    }
  }
  return prev[W];
}

int knapsack01Tabu(vector<int> &wt, vector<int> &val, int n, int W)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, 0));
  for (int i = wt[0]; i <= W; i++)
  {
    dp[0][i] = val[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int Wt = 0; Wt <= W; Wt++)
    {
      int take = 0;
      if (Wt >= wt[ind])
      {
        take = val[ind] + dp[ind - 1][Wt - wt[ind]];
      }
      int notTake = dp[ind - 1][Wt];
      dp[ind][Wt] = max(take, notTake);
    }
  }
  return dp[n - 1][W];
}

int helperMemo(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (W >= wt[0])
    {
      return val[0];
    }
    return 0;
  }
  if (dp[ind][W] != -1)
  {
    return dp[ind][W];
  }
  int take = 0;
  if (W >= wt[ind])
  {
    take = val[ind] + helperMemo(ind - 1, W - wt[ind], val, wt, dp);
  }
  int notTake = helperMemo(ind - 1, W, val, wt, dp);
  return dp[ind][W] = max(take, notTake);
}

int knapsack01Memo(vector<int> &wt, vector<int> &val, int n, int W)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  return helperMemo(n - 1, W, val, wt, dp);
}

int helperRecur(int ind, int W, vector<int> &val, vector<int> &wt)
{
  if (ind == 0)
  {
    if (W >= wt[0])
    {
      return val[0];
    }
    return 0;
  }
  int take = 0;
  if (W >= wt[ind])
  {
    take = val[ind] + helperRecur(ind - 1, W - wt[ind], val, wt);
  }
  int notTake = helperRecur(ind - 1, W, val, wt);
  return max(take, notTake);
}

int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
  return helperRecur(n - 1, W, val, wt);
}

int main()
{
  int n;
  cin >> n;
  vector<int> val;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    val.push_back(data);
  }
  vector<int> wt;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    wt.push_back(data);
  }

  cout << "Enter value of bag weight" << endl;
  int W;
  cin >> W;
  cout << knapsack01Space(wt, val, n, W) << endl;
  cout << knapsack01Tabu(wt, val, n, W) << endl;
  cout << knapsack01Memo(wt, val, n, W) << endl;
  cout << knapsack01(wt, val, n, W) << endl;
}