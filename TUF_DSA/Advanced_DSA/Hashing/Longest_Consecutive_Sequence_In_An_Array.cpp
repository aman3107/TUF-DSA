#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
  unordered_set<int> st;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    st.insert(nums[i]);
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
        cnt += 1;
        x += 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}

bool linearSearch(vector<int> &nums, int x)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == x)
    {
      return true;
    }
  }
  return false;
}

int longestConsecutiveBrute(vector<int> &nums)
{
  int n = nums.size();
  int longest = 1;
  for (int i = 0; i < n; i++)
  {
    int cnt = 1;
    int x = nums[i];
    while (linearSearch(nums, x + 1) == true)
    {
      cnt += 1;
      x += 1;
    }
    longest = max(longest, cnt);
  }
  return longest;
}

int longestConsecutiveBetter(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int longest = 1;
  int cnt = 0;
  int last_Smaller = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (last_Smaller == nums[i] - 1)
    {
      last_Smaller = nums[i];
      cnt += 1;
    }
    else if (nums[i] != last_Smaller)
    {
      last_Smaller = nums[i];
      cnt = 1;
    }
    longest = max(cnt, longest);
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
  cout << longestConsecutive(v) << endl;
}