#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(vector<int> &candidates, int target, int ind, vector<vector<int>> &ans, vector<int> temp)
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
  combinationSumHelper(candidates, target - candidates[ind], ind, ans, temp);
  temp.pop_back();
  combinationSumHelper(candidates, target, ind + 1, ans, temp);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  // your code goes here
  vector<vector<int>> ans;
  vector<int> temp;
  combinationSumHelper(candidates, target, 0, ans, temp);
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
  vector<vector<int>> ans = combinationSum(nums, k);
  for (auto sub : ans)
  {
    for (auto el : sub)
    {
      cout << el << " ";
    }
    cout << endl;
  }
}