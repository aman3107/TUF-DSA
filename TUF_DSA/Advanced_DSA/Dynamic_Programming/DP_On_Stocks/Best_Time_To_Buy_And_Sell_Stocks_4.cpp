#include <bits/stdc++.h>
using namespace std;

int stockBuySellSpace(vector<int> &arr, int n, int k)
{
  vector<vector<int>> prev(2, vector<int>(k + 1, 0));
  vector<vector<int>> curr(2, vector<int>(k + 1, 0));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      for (int cap = 1; cap <= k; cap++)
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
  return prev[1][k];
}

int stockBuySellTabu(vector<int> &arr, int n, int k)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      for (int cap = 1; cap <= k; cap++)
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
  return dp[0][1][k];
}

int helperMemo(int ind, int buy, int k, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
  if (ind == arr.size() || k == 0)
    return 0;

  if (dp[ind][buy][k] != -1)
  {
    return dp[ind][buy][k];
  }
  if (buy)
  {
    int profitBuy = helperMemo(ind + 1, 0, k, arr, dp) - arr[ind];
    int profitNotBuy = helperMemo(ind + 1, 1, k, arr, dp);
    return dp[ind][buy][k] = max(profitBuy, profitNotBuy);
  }
  else
  {
    int profitSell = helperMemo(ind + 1, 1, k - 1, arr, dp) + arr[ind];
    int prfitNotSell = helperMemo(ind + 1, 0, k, arr, dp);
    return dp[ind][buy][k] = max(profitSell, prfitNotSell);
  }
}

int stockBuySellMemo(vector<int> &arr, int n, int k)
{
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
  return helperMemo(0, 1, k, arr, dp);
}

int helperMemo(int ind, int buy, int k, vector<int> &arr)
{
  if (ind == arr.size() || k == 0)
    return 0;
  if (buy)
  {
    int profitBuy = helperMemo(ind + 1, 0, k, arr) - arr[ind];
    int profitNotBuy = helperMemo(ind + 1, 1, k, arr);
    return max(profitBuy, profitNotBuy);
  }
  else
  {
    int profitSell = helperMemo(ind + 1, 1, k - 1, arr) + arr[ind];
    int profitNotSell = helperMemo(ind + 1, 0, k, arr);
    return max(profitNotSell, profitSell);
  }
}

int stockBuySell(vector<int> arr, int n, int k)
{
  return helperMemo(0, 1, k, arr);
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
  cout << "enter k:" << endl;
  int k;
  cin >> k;
  cout << stockBuySellTabu(arr, n, k) << endl;
  cout << stockBuySellMemo(arr, n, k) << endl;
  cout << stockBuySell(arr, n, k) << endl;
}