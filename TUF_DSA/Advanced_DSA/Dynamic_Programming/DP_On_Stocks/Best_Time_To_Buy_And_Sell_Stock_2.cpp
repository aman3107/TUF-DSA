#include <bits/stdc++.h>
using namespace std;

int stockBuySellSpace(vector<int> &arr, int n)
{
  vector<int> prev(2, 0), curr(2, 0);
  prev[0] = 0;
  prev[1] = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      if (buy)
      {
        int profitBuy = prev[0] - arr[i];
        int profitNotBuy = prev[1];
        curr[buy] = max(profitBuy, profitNotBuy);
      }
      else
      {
        int profitSell = prev[1] + arr[i];
        int profitNotSell = prev[0];
        curr[buy] = max(profitSell, profitNotSell);
      }
    }
    prev = curr;
  }
  return prev[1];
}

int stockBuySellLeet(vector<int> &arr, int n)
{
  int profit = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > arr[i - 1])
    {
      profit += (arr[i] - arr[i - 1]);
    }
  }
  return profit;
}

int stockBuySellTabu(vector<int> &arr, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  dp[n][0] = 0;
  dp[n][1] = 0;
  int buy = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      if (buy)
      {
        int profitBuy = dp[i + 1][0] - arr[i];
        int profitNotBuy = dp[i + 1][1];
        dp[i][buy] = max(profitBuy, profitNotBuy);
      }
      else
      {
        int profitSell = dp[i + 1][1] + arr[i];
        int profitNotSell = dp[i + 1][0];
        dp[i][buy] = max(profitNotSell, profitSell);
      }
    }
  }
  return dp[0][1];
}

int helperMemo(int ind, int buy, vector<int> &arr, vector<vector<int>> &dp)
{
  if (ind == arr.size())
  {
    return 0;
  }

  if (dp[ind][buy] != -1)
  {
    return dp[ind][buy];
  }
  if (buy)
  {
    int profitBuy = helperMemo(ind + 1, 0, arr, dp) - arr[ind];
    int profitNotBuy = helperMemo(ind + 1, 1, arr, dp);
    return dp[ind][buy] = max(profitBuy, profitNotBuy);
  }
  else
  {
    int profitSell = helperMemo(ind + 1, 1, arr, dp) + arr[ind];
    int profitNotSell = helperMemo(ind + 1, 0, arr, dp);
    return dp[ind][buy] = max(profitSell, profitNotSell);
  }
}

int stockBuySellMemo(vector<int> &arr, int n)
{
  vector<vector<int>> dp(n, vector<int>(2, -1));
  return helperMemo(0, 1, arr, dp);
}

int helperRecur(int ind, int buy, vector<int> &arr)
{
  if (ind == arr.size())
    return 0;

  if (buy)
  {
    int profitBuy = helperRecur(ind + 1, 0, arr) - arr[ind];
    int profitNotBuy = helperRecur(ind + 1, 1, arr);
    return max(profitNotBuy, profitBuy);
  }
  else
  {
    int profitSell = helperRecur(ind + 1, 1, arr) + arr[ind];
    int profitNotSell = helperRecur(ind + 1, 0, arr);
    return max(profitSell, profitNotSell);
  }
}

int stockBuySell(vector<int> arr, int n)
{
  return helperRecur(0, 1, arr);
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
  cout << stockBuySellSpace(arr, n) << endl;
  cout << stockBuySellTabu(arr, n) << endl;
  cout << stockBuySellLeet(arr, n) << endl;
  cout << stockBuySellMemo(arr, n) << endl;
  cout << stockBuySell(arr, n) << endl;
}