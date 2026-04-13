#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
  int pos = 0;
  int neg = 1;
  int n = nums.size();
  vector<int> ans(n, 0);
  for (int i = 0; i < nums.size(); i++)
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
  vector<int> ans;
  int n = nums.size();
  ans.push_back(nums[n - 1]);
  int maxi = nums[n - 1];
  for (int i = n - 2; i > 0; i--)
  {
    if (nums[i] > maxi)
    {
      ans.push_back(nums[i]);
      maxi = nums[i];
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
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
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}