#include <bits/stdc++.h>
using namespace std;

int countSubsequenceWithTargetSumHelper(vector<int> &nums, int n, int ind, int k)
{

  if (k == 0)
  {
    return 1;
  }
  if (k < 0 || ind == n)
  {
    return 0;
  }

  return countSubsequenceWithTargetSumHelper(nums, n, ind + 1, k - nums[ind]) + countSubsequenceWithTargetSumHelper(nums, n, ind + 1, k);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k)
{
  // your code goes here
  int n = nums.size();
  return countSubsequenceWithTargetSumHelper(nums, n, 0, k);
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
  cout << countSubsequenceWithTargetSum(nums, k) << endl;
}