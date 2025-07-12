#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> &arr)
{
  int n = arr.size();
  vector<int> dp(n, 1);
  vector<int> hash(n, 0);
  int maxi = 1;
  int lastIndex = 0;
  for (int i = 0; i < n; i++)
  {
    hash[i] = i;
    for (int prev = 0; prev < i; prev++)
    {
      if (arr[i] > arr[prev] && 1 + dp[prev] > dp[i])
      {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
    if (dp[i] > maxi)
    {
      maxi = dp[i];
      lastIndex = i;
    }
  }
  vector<int> ans;
  ans.push_back(arr[lastIndex]);
  while (hash[lastIndex] != lastIndex)
  {
    lastIndex = hash[lastIndex];
    ans.push_back(arr[lastIndex]);
  }
  reverse(ans.begin(), ans.end());
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
  vector<int> ans = longestIncreasingSubsequence(arr);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}