#include <bits/stdc++.h>
using namespace std;

void combination3Helper(int sum, vector<int> &arr, vector<vector<int>> &ans, int k)
{
  if (sum < 0 || arr.size() > k)
    return;
  if (sum == 0)
  {
    if (arr.size() == k)
    {
      ans.push_back(arr);
    }
    return;
  }
  int ind = arr.size() == 0 ? 1 : arr.back() + 1;
  for (int i = ind; i <= 9; i++)
  {
    if (i > sum)
      break;
    arr.push_back(i);
    combination3Helper(sum - i, arr, ans, k);
    arr.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n)
{
  // your code goes here
  vector<int> arr;
  vector<vector<int>> ans;
  combination3Helper(n, arr, ans, k);
  return ans;
}

void subsetsDupHelper(int ind, int n, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans)
{
  if (ind == n)
  {
    ans.push_back(arr);
    return;
  }

  arr.push_back(nums[ind]);
  subsetsDupHelper(ind + 1, n, arr, nums, ans);
  arr.pop_back();
  for (int i = ind + 1; i < n; i++)
  {
    if (nums[i] != nums[ind])
    {
      subsetsDupHelper(i, n, arr, nums, ans);
      return;
    }
  }
  subsetsDupHelper(n, n, arr, nums, ans);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  // your code goes here
  vector<int> arr;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  subsetsDupHelper(0, nums.size(), arr, nums, ans);
  return ans;
}

void subsetsHelper(int ind, int n, vector<int> &ans, vector<int> &nums, int sum)
{
  if (ind == n)
  {
    ans.push_back(sum);
    return;
  }

  // take
  subsetsHelper(ind + 1, n, ans, nums, sum + nums[ind]);
  subsetsHelper(ind + 1, n, ans, nums, sum);
}

vector<int> subsetSums(vector<int> &nums)

{
  // your code goes here
  vector<int> ans;
  subsetsHelper(0, nums.size(), ans, nums, 0);
  return ans;
}

void combination2Helper(int ind, int n, int sum, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans)
{
  if (sum == 0)
  {
    ans.push_back(arr);
    return;
  }
  if (sum < 0 || ind == n)
    return;

  // take
  arr.push_back(nums[ind]);
  combination2Helper(ind + 1, n, sum - nums[ind], arr, nums, ans);
  arr.pop_back();
  for (int i = ind + 1; i < n; i++)
  {
    if (nums[i] != nums[ind])
    {
      combination2Helper(i, n, sum, arr, nums, ans);
      break;
    }
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  // your code goes here
  vector<int> arr;
  vector<vector<int>> ans;
  sort(candidates.begin(), candidates.end());
  combination2Helper(0, candidates.size(), target, arr, candidates, ans);
  return ans;
}

void combination1Helper(int ind, int n, vector<int> &arr, vector<int> &nums, int sum, vector<vector<int>> &ans)
{
  if (sum == 0)
  {
    ans.push_back(arr);
    return;
  }
  if (sum < 0 || ind == n)
  {
    return;
  }

  arr.push_back(nums[ind]);
  // take element
  combination1Helper(ind, n, arr, nums, sum - nums[ind], ans);
  arr.pop_back();
  // not take element
  combination1Helper(ind + 1, n, arr, nums, sum, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  // your code goes here
  vector<int> arr;
  vector<vector<int>> ans;
  combination1Helper(0, candidates.size(), arr, candidates, target, ans);
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

  int target;
  cin >> target;
  vector<vector<int>> ans = combinationSum(nums, target);
  for (auto it : ans)
  {
    for (auto i : it)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}