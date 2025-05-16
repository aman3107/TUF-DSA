#include <bits/stdc++.h>
using namespace std;

int singleNumber2Optimal(vector<int> &nums)
{
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    ones = (ones ^ nums[i]) & (~twos);
    twos = (twos ^ nums[i]) & (~ones);
  }
  return ones;
}

int singleNumber2Better2(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i += 3)
  {
    if (nums[i] != nums[i - 1])
    {
      return nums[i - 1];
    }
  }
  return nums[nums.size() - 1];
}

int singleNumber2Better1(vector<int> &nums)
{
  int ans = 0;

  for (int bitIndex = 0; bitIndex < 32; bitIndex++)
  {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] & (1 << bitIndex)) // Check set bits
      {
        cnt++; // Count how many setBits at particular bit Index
      }
    }
    if (cnt % 3 == 1)
    {
      ans = ans | (1 << bitIndex); // Set the set bit in bitIndex position in ans
    }
  }
  return ans;
}

int singleNumber2Brute(vector<int> &nums)
{
  unordered_map<int, int> ump;
  for (int i = 0; i < nums.size(); i++)
  {
    ump[nums[i]]++;
  }
  for (auto it : ump)
  {
    if (it.second == 1)
    {
      return it.first;
    }
  }
  return 0;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    v.push_back(ele);
  }
  cout << singleNumber2Optimal(v) << endl;
}