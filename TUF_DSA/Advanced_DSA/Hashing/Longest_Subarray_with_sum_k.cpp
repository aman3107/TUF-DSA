#include <bits/stdc++.h>
using namespace std;

int longestSubarrayOptimal(vector<int> &nums, int k)
{
  int n = nums.size();
  int left = 0;
  int right = 0;
  int maxLength = 0;
  int sum = nums[0];
  while (right < n)
  {
    while (left <= right && sum > k)
    {
      sum -= nums[left];
      left++;
    }
    if (sum == k)
    {
      int len = right - left + 1;
      maxLength = max(maxLength, len);
    }
    right++;
    if (right < n)
    {
      sum += nums[right];
    }
  }
  return maxLength;
}

int longestSubarrayBetter(vector<int> &nums, int k)
{
  int n = nums.size();
  unordered_map<int, int> mp;
  int maxLength = 0;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    if (sum == k)
    {
      maxLength = max(maxLength, i + 1);
    }
    int rem = sum - k;
    if (mp.find(rem) != mp.end())
    {
      int len = i - mp[rem];
      maxLength = max(len, maxLength);
    }
    if (mp.find(sum) == mp.end())
    {
      mp[sum] = i;
    }
  }
  return maxLength;
}

int longestSubarrayBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  int longest = 0;
  for (int i = 0; i < n; i++)
  {
    int currentSum = 0;
    for (int j = i; j < n; j++)
    {
      currentSum += nums[j];
      if (currentSum == k)
      {
        longest = max(longest, (j - i) + 1);
      }
    }
  }
  return longest;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }
  int k;
  cin >> k;
  cout << longestSubarrayBetter(v, k) << endl;
}