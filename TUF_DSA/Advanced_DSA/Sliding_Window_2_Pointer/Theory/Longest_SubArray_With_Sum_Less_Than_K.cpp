#include <bits/stdc++.h>
using namespace std;
int longestSubArrayWithSumKOptimal(vector<int> &arr, int k)
{
  int n = arr.size();
  int maxLen = 0;
  int r = 0;
  int l = 0;
  int sum = 0;
  while (r < n)
  {
    sum += arr[r];
    if (sum > k)
    {
      sum -= arr[l];
      l++;
    }
    else
    {
      maxLen = max(maxLen, r - l + 1);
      r++;
    }
  }
  return maxLen;
}

int longestSubArrayWithSumKBetter(vector<int> &arr, int k)
{
  int l = 0;
  int r = 0;
  int sum = 0;
  int maxLen = 0;
  int n = arr.size();
  while (r < n)
  {
    sum = sum + arr[r];

    while (sum > k)
    {
      sum = sum - arr[l];
      l++;
    }
    if (sum <= k)
    {
      maxLen = max(maxLen, r - l + 1);
      r++;
    }
  }
  return maxLen;
}

int longestSubArrayWithSumKBrute(vector<int> &arr, int k)
{
  int n = arr.size();
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum = sum + arr[j];
      if (sum <= k)
      {
        maxLen = max(maxLen, j - i + 1);
      }
      else if (sum > k)
      {
        break;
      }
    }
  }
  return maxLen;
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
  int k;
  cin >> k;
  cout << longestSubArrayWithSumKOptimal(arr, k) << endl;
}