#include <bits/stdc++.h>
using namespace std;

void subsetSumsHelper(vector<int> &nums, int ind, int sum, vector<int> &ans)
{
  // your code goes here
  if (ind == nums.size())
  {
    ans.push_back(sum);
    return;
  }
  subsetSumsHelper(nums, ind + 1, sum + nums[ind], ans);
  subsetSumsHelper(nums, ind + 1, sum, ans);
}

vector<int> subsetSums(vector<int> &nums)
{
  // your code goes here
  vector<int> ans;
  subsetSumsHelper(nums, 0, 0, ans);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> ans = subsetSums(nums);
  for (int a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
}