#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackSpace(vector<int> &wt, vector<int> &val, int n, int W)
{
  // Create a vector to store current DP state
  vector<int> curr(W + 1, 0);

  // Base Condition
  for (int i = 0; i <= W; i++)
  {
    // Calculate the maximum value for first item
    curr[i] = (int)(i / wt[0]) * val[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int Wt = 0; Wt <= W; Wt++)
    {
      // Maximum value by taking current item
      int take = 0;
      if (Wt >= wt[ind])
      {
        take = val[ind] + curr[Wt - wt[ind]];
      }
      // Maximum value without taking current item
      int notTake = curr[Wt];
      /* Store the maximum value
                in the current DP state*/
      curr[Wt] = max(take, notTake);
    }
  }
  /* Return the maximum value considering
        all items and the knapsack capacity*/
  return curr[W];
}

int unboundedKnapsackTabu(vector<int> &wt, vector<int> &val, int n, int W)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, 0));
  for (int i = 0; i <= W; i++)
  {
    dp[0][i] = (int)(i / wt[0]) * val[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int Wt = 0; Wt <= W; Wt++)
    {
      int take = 0;
      if (Wt >= wt[ind])
      {
        take = val[ind] + dp[ind][Wt - wt[ind]];
      }
      int notTake = dp[ind - 1][Wt];
      dp[ind][Wt] = max(take, notTake);
    }
  }
  return dp[n - 1][W];
}

int helperMemo(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    return (int)(W / wt[0]) * val[0];
  }
  if (dp[ind][W] != -1)
  {
    return dp[ind][W];
  }
  int take = 0;
  if (W >= wt[ind])
  {
    take = val[ind] + helperMemo(ind, W - wt[ind], wt, val, dp);
  }
  int notTake = helperMemo(ind - 1, W, wt, val, dp);
  return dp[ind][W] = max(take, notTake);
}

int unboundedKnapsackMemo(vector<int> &wt, vector<int> &val, int n, int W)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  return helperMemo(n - 1, W, wt, val, dp);
}

int helperRecur(int ind, int W, vector<int> &wt, vector<int> &val)
{
  if (ind == 0)
  {
    return (int)(W / wt[0]) * val[0];
  }
  int take = 0;
  if (W >= wt[ind])
  {
    take = val[ind] + helperRecur(ind, W - wt[ind], wt, val);
  }
  int notTake = helperRecur(ind - 1, W, wt, val);
  return max(take, notTake);
}

int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
  return helperRecur(n - 1, W, wt, val);
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
  cout << unboundedKnapsackMemo(wt, val, n, W) << endl;
  cout << unboundedKnapsack(wt, val, n, W) << endl;
}