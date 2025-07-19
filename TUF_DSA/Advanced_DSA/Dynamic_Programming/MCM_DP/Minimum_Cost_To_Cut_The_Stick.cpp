#include <bits/stdc++.h>
using namespace std;

int minCostTabu(int n, vector<int> &cuts)
{
  // your code goes here
  int c = cuts.size();
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
  for (int i = c; i >= 1; i--)
  {
    for (int j = 1; j <= c; j++)
    {
      if (i > j)
      {
        continue;
      }
      int mini = INT_MAX;
      for (int ind = i; ind <= j; ind++)
      {
        int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][ind - 1] + dp[ind + 1][j];
        mini = min(cost, mini);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][c];
}

int helperMemo(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];
  int mini = INT_MAX;
  for (int ind = i; ind <= j; ind++)
  {
    int cost = (cuts[j + 1] - cuts[i - 1]) + helperMemo(i, ind - 1, cuts, dp) + helperMemo(ind + 1, j, cuts, dp);
    mini = min(cost, mini);
  }
  return dp[i][j] = mini;
}

int minCostMemo(int n, vector<int> &cuts)
{
  // your code goes here
  int c = cuts.size();
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
  return helperMemo(1, c, cuts, dp);
}

int helper(int i, int j, vector<int> &cuts)
{
  if (i > j)
    return 0;

  int mini = INT_MAX;
  for (int ind = i; ind <= j; ind++)
  {
    int cost = (cuts[j + 1] - cuts[i - 1]) + helper(i, ind - 1, cuts) + helper(ind + 1, j, cuts);
    mini = min(cost, mini);
  }
  return mini;
}

int minCost(int n, vector<int> &cuts)
{
  // your code goes here
  int c = cuts.size();
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  return helper(1, c, cuts);
}

int main()
{
  int n;
  cin >> n;
  vector<int> cuts;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    cuts.push_back(data);
  }
  int m;
  cin >> m;
  cout << minCostMemo(m, cuts) << endl;
  // cout << minCost(m, cuts) << endl;
}