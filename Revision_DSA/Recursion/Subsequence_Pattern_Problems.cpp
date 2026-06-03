#include <bits/stdc++.h>
using namespace std;

int helperCount(int ind, int sum, int k, vector<int> &nums, int n)
{
  if (ind == n)
  {
    if (sum == k)
    {
      return 1;
    }
    return 0;
  }

  return helperCount(ind + 1, sum + nums[ind], k, nums, n) + helperCount(ind + 1, sum, k, nums, n);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k)
{
  // your code goes here
  return helperCount(0, 0, k, nums, nums.size());
}

bool helperSum(int ind, int n, int sum, vector<int> &nums, int k)
{
  if (sum > k)
    return false;
  if (ind == n)
  {
    if (sum == k)
      return true;
    return false;
  }

  return helperSum(ind + 1, n, sum + nums[ind], nums, k) || helperSum(ind + 1, n, sum, nums, k);
}

bool checkSubsequenceSum(vector<int> &nums, int k)
{
  // your code goes here
  return helperSum(0, nums.size(), 0, nums, k);
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
  int k;
  cin >> k;
  cout << checkSubsequenceSum(nums, k);
}