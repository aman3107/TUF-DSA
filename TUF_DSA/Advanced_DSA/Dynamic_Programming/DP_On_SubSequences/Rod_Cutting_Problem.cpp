#include <bits/stdc++.h>
using namespace std;

int rodCuttingSpace(vector<int> &price, int n)
{
  // Initialize DP table with dimensions [n + 1]
  vector<int> prev(n + 1, 0);
  vector<int> curr(n + 1, 0);
  for (int i = 0; i <= n; i++)
  {
    // Calculating all the  rod length at index 0 multiplying with price at index 0
    prev[i] = (i)*price[0];
  }
  // Fill the DP table
  for (int ind = 1; ind < n; ind++)
  {
    for (int N = 1; N <= n; N++)
    {
      // Take  condition if Rod Length(N) is greater than Rod of Length(ind+1)
      int take = 0;
      if (N >= (ind + 1))
      {
        take = price[ind] + curr[N - (ind + 1)];
      }

      // Not Take condition just move to next index
      int notTake = prev[N];

      // Calculate max of take and notTake
      curr[N] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[n];
}

int rodCuttingTabu(vector<int> &price, int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, 0));
  for (int i = 0; i <= n; i++)
  {
    // Calculating all the  rod length at index 0 multiplying with price at index 0
    dp[0][i] = (i)*price[0];
  }
  for (int ind = 1; ind < n; ind++)
  {
    for (int N = 1; N <= n; N++)
    {
      // Take  condition if Rod Length(N) is greater than Rod of Length(ind+1)
      int take = 0;
      if (N >= (ind + 1))
      {
        take = price[ind] + dp[ind][N - (ind + 1)];
      }

      // Not Take condition just move to next index
      int notTake = dp[ind - 1][N];

      // Calculate max of take and notTake
      dp[ind][N] = max(take, notTake);
    }
  }
  return dp[n - 1][n];
}

int helperMemo(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
  // Base Condition
  if (ind == 0)
  {
    // In Base condition Rod of length is 1. So, we can just multiply with the remaining Rod length N with price at index 0
    return N * price[0];
  }

  // dp check if answer is already present for the funtion call
  if (dp[ind][N] != -1)
  {
    return dp[ind][N];
  }

  // Take  condition if Rod Length(N) is greater than Rod of Length(ind+1)
  int take = 0;
  if (N >= (ind + 1))
  {
    take = price[ind] + helperMemo(ind, N - (ind + 1), price, dp);
  }

  // Not Take condition just move to next index
  int notTake = helperMemo(ind - 1, N, price, dp);

  // Recturn max of take and notTake
  return dp[ind][N] = max(take, notTake);
}

int rodCuttingMemo(vector<int> &price, int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return helperMemo(n - 1, n, price, dp);
}

int helperRecur(int ind, int N, vector<int> &price)
{

  // Base Condition
  if (ind == 0)
  {
    // In Base condition Rod of length is 1. So, we can just multiply with the remaining Rod length N with price at index 0
    return N * price[0];
  }

  // Take  condition if Rod Length(N) is greater than Rod of Length(ind+1)
  int take = 0;
  if (N >= (ind + 1))
  {
    take = price[ind] + helperRecur(ind, N - (ind + 1), price);
  }

  // Not Take condition just move to next index
  int notTake = helperRecur(ind - 1, N, price);

  // Recturn max of take and notTake
  return max(take, notTake);
}

int rodCutting(vector<int> price, int n)
{
  return helperRecur(n - 1, n, price);
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
  cout << rodCuttingTabu(val, n) << endl;
  cout << rodCuttingMemo(val, n) << endl;
  cout << rodCutting(val, n) << endl;
}