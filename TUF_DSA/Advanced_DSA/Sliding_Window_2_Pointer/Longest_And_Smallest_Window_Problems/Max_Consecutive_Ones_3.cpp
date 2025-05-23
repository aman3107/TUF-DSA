#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
  int n = nums.size();
  int r = 0;
  int l = 0;
  int maxLen = 0;
  int zeros = 0;
  while (r < n)
  {
    if (nums[r] == 0)
    {
      zeros++;
    }
    if (zeros > k)
    {
      if (nums[l] == 0)
      {
        zeros--;
      }
      l++;
    }
    int len = r - l + 1;
    maxLen = max(maxLen, len);
    r++;
  }
  return maxLen;
}

int longestOnesBetter(vector<int> &nums, int k)
{
  int maxLen = 0;
  int n = nums.size();
  int r = 0;
  int l = 0;
  int zeros = 0;
  while (r < n)
  {
    if (nums[r] == 0)
    {
      zeros++;
    }
    while (zeros > k)
    {
      if (nums[l] == 0)
      {
        zeros--;
      }
      l++;
    }
    int len = r - l + 1;
    maxLen = max(maxLen, len);
    r++;
  }
  return maxLen;
}

int longestOnesBrute(vector<int> &nums, int k)
{
  // your code goes here
  int n = nums.size();
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    int len = 0;
    int zeros = 0;
    for (int j = i; j < n; j++)
    {
      if (nums[j] == 0)
      {
        if (zeros == k)
        {
          break;
        }
        else
        {
          zeros++;
        }
      }
      len++;
    }
    maxLen = max(maxLen, len);
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
  cout << longestOnes(arr, k) << endl;
}