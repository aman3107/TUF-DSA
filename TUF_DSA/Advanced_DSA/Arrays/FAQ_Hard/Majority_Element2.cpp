#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementTwo(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  int cnt1 = 0;
  int cnt2 = 0;
  int el1 = INT_MIN, el2 = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (cnt1 == 0 && el2 != nums[i])
    {
      cnt1 = 1;
      el1 = nums[i];
    }
    else if (cnt2 == 0 && el1 != nums[i])
    {
      cnt2 = 1;
      el2 = nums[i];
    }
    else if (nums[i] == el1)
    {
      cnt1 += 1;
    }
    else if (nums[i] == el2)
    {
      cnt2 += 1;
    }
    else
    {
      cnt1--;
      cnt2--;
    }
  }
  int cnt3 = 0, cnt4 = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == el1)
    {
      cnt3++;
    }
    else if (nums[i] == el2)
    {
      cnt4++;
    }
  }
  if (cnt3 > (n / 3))
  {
    ans.push_back(el1);
  }
  if (cnt4 > (n / 3))
  {
    ans.push_back(el2);
  }
  return ans;
}

vector<int> majorityElementTwoBetter(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[nums[i]]++;
    if (mp[nums[i]] > (n / 3))
    {
      ans.push_back(nums[i]);
      mp[nums[i]] = 0;
    }
  }
  return ans;
}

vector<int> majorityElementTwoBrute(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (ans.size() == 0 || ans[0] != nums[i])
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {

        if (nums[i] == nums[j])
        {
          cnt++;
        }
      }
      if (cnt > (n / 3))
      {
        ans.push_back(nums[i]);
      }
      if (ans.size() == 2)
      {
        break;
      }
    }
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
    int val;
    cin >> val;
    v.push_back(val);
  }
  vector<int> ans = majorityElementTwoBetter(v);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}