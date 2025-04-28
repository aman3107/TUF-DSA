#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int target)
{
  int low = 0;
  int high = nums.size() - 1;
  int ans = nums.size();
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] > target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

void combinationSum2Helper(vector<int> &candidates, int target, int ind, vector<vector<int>> &ans, vector<int> temp)
{
  // your code goes here
  if (target == 0)
  {
    ans.push_back(temp);
    return;
  }
  if (target < 0 || ind == candidates.size())
  {
    return;
  }

  temp.push_back(candidates[ind]);
  combinationSum2Helper(candidates, target - candidates[ind], ind + 1, ans, temp);
  temp.pop_back();
  for (int i = ind + 1; i < candidates.size(); i++)
  {
    if (candidates[i] != candidates[ind])
    {
      combinationSum2Helper(candidates, target, i, ans, temp);
      break;
    }
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  // your code goes here
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> temp;
  combinationSum2Helper(candidates, target, 0, ans, temp);
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
  int k;
  cin >> k;
  cout << upperBound(nums, k) << endl;
  vector<vector<int>> ans = combinationSum2(nums, k);
  for (auto sub : ans)
  {
    for (auto el : sub)
    {
      cout << el << " ";
    }
    cout << endl;
  }
}