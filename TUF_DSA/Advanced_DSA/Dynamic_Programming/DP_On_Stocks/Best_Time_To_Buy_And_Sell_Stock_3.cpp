#include <bits/stdc++.h>
using namespace std;

int stockBuySellSpace(vector<int> &arr, int n)
{
  vector<vector<int>> prev(2, vector<int>(3, 0));
  vector<vector<int>> curr(2, vector<int>(3, 0));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        if (buy)
        {
          int profitBuy = prev[0][cap] - arr[ind];
          int profitNotBuy = prev[1][cap];
          curr[buy][cap] = max(profitBuy, profitNotBuy);
        }
        else
        {
          int profitSell = prev[1][cap - 1] + arr[ind];
          int profitNotSell = prev[0][cap];
          curr[buy][cap] = max(profitNotSell, profitSell);
        }
      }
    }
    prev = curr;
  }
  return prev[1][2];
}

int stockBuySellTabu(vector<int> &arr, int n)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        if (buy)
        {
          int profitBuy = dp[ind + 1][0][cap] - arr[ind];
          int profitNotBuy = dp[ind + 1][1][cap];
          dp[ind][buy][cap] = max(profitBuy, profitNotBuy);
        }
        else
        {
          int profitSell = dp[ind + 1][1][cap - 1] + arr[ind];
          int profitNotSell = dp[ind + 1][0][cap];
          dp[ind][buy][cap] = max(profitNotSell, profitSell);
        }
      }
    }
  }
  return dp[0][1][2];
}

int helperMemo(int ind, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
  if (cap == 0)
    return 0;
  if (ind == arr.size())
    return 0;

  if (dp[ind][buy][cap] != -1)
    return dp[ind][buy][cap];
  if (buy)
  {
    int profitBuy = helperMemo(ind + 1, 0, cap, arr, dp) - arr[ind];
    int profitNotBuy = helperMemo(ind + 1, 1, cap, arr, dp);
    return dp[ind][buy][cap] = max(profitBuy, profitNotBuy);
  }
  else
  {
    int profitSell = helperMemo(ind + 1, 1, cap - 1, arr, dp) + arr[ind];
    int profitNotSell = helperMemo(ind + 1, 0, cap, arr, dp);
    return dp[ind][buy][cap] = max(profitNotSell, profitSell);
  }
}

int stockBuySellMemo(vector<int> &arr, int n)
{
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
  return helperMemo(0, 1, 2, arr, dp);
}

int helperRecur(int ind, int buy, int cap, vector<int> &arr)
{
  if (cap == 0)
    return 0;
  if (ind == arr.size())
    return 0;
  if (buy)
  {
    int proifitBuy = helperRecur(ind + 1, 0, cap, arr) - arr[ind];
    int profitNotBuy = helperRecur(ind + 1, 1, cap, arr);
    return max(profitNotBuy, proifitBuy);
  }
  else
  {
    int profitSell = helperRecur(ind + 1, 1, cap - 1, arr) + arr[ind];
    int profitNotSell = helperRecur(ind + 1, 0, cap, arr);
    return max(profitNotSell, profitSell);
  }
}

int stockBuySell(vector<int> arr, int n)
{
  return helperRecur(0, 1, 2, arr);
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
  cout << stockBuySellMemo(arr, n) << endl;
  cout << stockBuySell(arr, n) << endl;
}