#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void forward(vector<int> &arr, vector<int> &dp)
  {
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
        {
          dp[i] = 1 + dp[j];
        }
      }
    }
  }

  void backward(vector<int> &arr, vector<int> &dp)
  {
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = n - 1; j > i; j--)
      {
        if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
        {
          dp[i] = 1 + dp[j];
        }
      }
    }
  }

public:
  int minimumMountainRemovals(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    forward(arr, dp1);
    backward(arr, dp2);

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp1[i] != 1 && dp2[i] != 1)
        maxi = max(maxi, (dp1[i] + dp2[i]) - 1);
    }
    return n - maxi;
  }
};