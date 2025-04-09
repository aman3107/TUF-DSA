#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k)
{
  unordered_map<int, int> mp;
  int xr = 0;
  int cnt = 0;
  mp[xr] = 1;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    xr = xr ^ nums[i];
    int rem = xr ^ k;
    if (mp.find(rem) != mp.end())
    {
      cnt += mp[rem];
    }
    mp[xr] += 1;
  }
  return cnt;
}

int subarraysWithXorKBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int x = 0;
    for (int j = i; j < n; j++)
    {
      x = x ^ nums[j];
      if (x == k)
      {
        count++;
      }
    }
  }
  return count;
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
  cout << subarraysWithXorK(v, k) << endl;
}