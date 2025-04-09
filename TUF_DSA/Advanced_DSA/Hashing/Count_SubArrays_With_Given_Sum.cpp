#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  unordered_map<int, int> mp;
  int count = 0;
  int prefixSum = 0;
  int n = nums.size();
  mp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    prefixSum += nums[i];
    int rem = prefixSum - k;
    if (mp.find(rem) != mp.end())
    {
      count += mp[rem];
    }
    mp[prefixSum] += 1;
  }
  return count;
}

int subarraySumBrute(vector<int> &nums, int k)
{
  int count = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum == k)
      {
        count++;
      }
    }
  }
  return count;

  // TC = O(N2)
  // SC = O(1)
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
  cout << subarraySumBrute(v, k) << endl;
}