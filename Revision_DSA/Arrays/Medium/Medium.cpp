#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, 0);
  int pos = 0;
  int neg = 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= 0)
    {
      ans[pos] = nums[i];
      pos += 2;
    }
    else
    {
      ans[neg] = nums[i];
      neg += 2;
    }
  }
  return ans;
}

vector<int> leaders(vector<int> &nums)
{
  int n = nums.size() - 1;
  vector<int> ans;
  int leader = nums[n];
  ans.push_back(leader);
  n--;
  while (n >= 0)
  {
    if (nums[n] > leader)
    {
      ans.push_back(nums[n]);
      leader = nums[n];
    }
    n--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int majorityElement(vector<int> &nums)
{
  int cnt = 0;
  int ele;
  for (int num : nums)
  {
    if (cnt == 0)
    {
      ele = num;
      cnt++;
    }
    else if (ele == num)
    {
      cnt++;
    }
    else
    {
      cnt--;
    }
  }
  return ele;
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

  vector<int> ans = leaders(nums);
  for (int a : ans)
  {
    cout << a << " ";
  }
}