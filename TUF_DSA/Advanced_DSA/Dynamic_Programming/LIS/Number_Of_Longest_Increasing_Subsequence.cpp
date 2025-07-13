#include <bits/stdc++.h>
using namespace std;

int numberOfLIS(vector<int> nums)
{
  int n = nums.size();
  vector<int> dp(n, 1);
  vector<int> cnt(n, 1);
  int maxi = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
      {
        dp[i] = 1 + dp[j];
        cnt[i] = cnt[j];
      }
      else if (nums[i] > nums[j] && 1 + dp[j] == dp[i])
      {
        cnt[i] += cnt[j];
      }
    }
    maxi = max(maxi, dp[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (dp[i] == maxi)
    {
      ans += cnt[i];
    }
  }
  return ans;
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
  cout << numberOfLIS(arr) << endl;
}