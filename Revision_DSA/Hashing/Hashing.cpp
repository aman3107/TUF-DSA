#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k)
{
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int prefixXor = 0;
  int cnt = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    prefixXor ^= nums[i];
    int x = prefixXor ^ k;
    if (mpp.find(x) != mpp.end())
    {
      cnt += mpp[x];
    }
    mpp[prefixXor]++;
  }
  return cnt;
}

int subarraySum(vector<int> &nums, int k)
{
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int cnt = 0;
  int prefixSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    prefixSum += nums[i];
    int remSum = prefixSum - k;
    if (mpp.find(remSum) != mpp.end())
    {
      cnt += mpp[remSum];
    }
    mpp[prefixSum]++;
  }
  return cnt;
}

int longestSubarray(vector<int> &nums, int k)
{
  unordered_map<int, int> mpp;
  int prefixSum = 0;
  int maxLen = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    prefixSum += nums[i];
    if (prefixSum == k)
    {
      maxLen = max(maxLen, i + 1);
    }
    int remSum = prefixSum - k;
    if (mpp.find(remSum) != mpp.end())
    {
      int len = i - mpp[remSum];
      maxLen = max(len, maxLen);
    }
    if (mpp.find(prefixSum) == mpp.end())
      mpp[prefixSum] = i;
  }
  return maxLen;
}

int longestConsecutive(vector<int> &nums)
{
  if (nums.size() == 0)
    return 0;
  unordered_set<int> st;
  for (int num : nums)
  {
    st.insert(num);
  }

  int longest = 1;
  for (auto it : st)
  {

    if (st.find(it - 1) == st.end())
    {
      int cnt = 1;
      int x = it;

      while (st.find(x + 1) != st.end())
      {
        x = x + 1;
        cnt = cnt + 1;
      }
      longest = max(cnt, longest);
    }
  }
  return longest;
}

int longestConsecutiveBetter(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int longest = 1;
  int cnt = 0;
  int lastSmaller = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {

    if (nums[i] - 1 == lastSmaller)
    {
      cnt++;
      lastSmaller = nums[i];
    }
    else if (nums[i] != lastSmaller)
    {
      lastSmaller = nums[i];
      cnt = 1;
    }
    longest = max(longest, cnt);
  }
  return longest;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums.push_back(data);
  }
  int k;
  cin >> k;
  cout << longestSubarray(nums, k);
}