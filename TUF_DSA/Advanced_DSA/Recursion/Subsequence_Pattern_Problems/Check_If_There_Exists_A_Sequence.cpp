#include <bits/stdc++.h>
using namespace std;

bool checkSubsequenceSumHelper(vector<int> &nums, int k, int ind)
{
  if (k == 0)
  {
    return true;
  }
  if (k < 0 || ind == nums.size())
  {
    return false;
  }
  return checkSubsequenceSumHelper(nums, k - nums[ind], ind + 1) || checkSubsequenceSumHelper(nums, k, ind + 1);
}

bool checkSubsequenceSum(vector<int> &nums, int k)
{
  // your code goes here
  return checkSubsequenceSumHelper(nums, k, 0);
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
  int k;
  cin >> k;
  cout << checkSubsequenceSum(nums, k) << endl;
}