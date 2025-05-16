#include <bits/stdc++.h>
using namespace std;

int singleNumberBrute(vector<int> &nums)
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

int singleNumber(vector<int> &nums)
{
  // your code goes here
  int ans = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    ans = ans ^ nums[i];
  }
  return ans;
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
  cout << singleNumberBrute(v) << endl;
}