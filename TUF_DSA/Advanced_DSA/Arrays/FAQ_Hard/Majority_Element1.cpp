#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
  int n = nums.size();
  int cnt0 = 0;
  int el;
  for (int i = 0; i < n; i++)
  {
    if (cnt0 == 0)
    {
      el = nums[i];
      cnt0++;
    }
    else if (nums[i] == el)
    {
      cnt0++;
    }
    else
    {
      cnt0--;
    }
  }
  int cnt1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == el)
    {
      cnt1++;
    }
  }
  if (cnt1 > (n / 2))
  {
    return el;
  }
  else
  {
    return -1;
  }
}

int majorityElementBrute(vector<int> &nums)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (nums[i] == nums[j])
      {
        cnt++;
      }
    }
    if (cnt > n / 2)
    {
      return nums[i];
    }
  }
}

int majorityElementBetter(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[nums[i]]++;
  }
  for (auto pair : mp)
  {
    if (pair.second > (n / 2))
    {
      return pair.first;
    }
  }
  return 0;

  // TC = O(NlogN)
  // SC = O(N)
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
  cout << majorityElement(v) << endl;
}