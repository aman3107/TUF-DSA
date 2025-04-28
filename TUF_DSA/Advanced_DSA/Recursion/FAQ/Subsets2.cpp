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

void subsetSumsHelper(vector<int> &nums, int ind, vector<int> temp, vector<vector<int>> &ans)
{
  // your code goes here
  if (ind == nums.size())
  {
    ans.push_back(temp);
    return;
  }
  temp.push_back(nums[ind]);
  subsetSumsHelper(nums, ind + 1, temp, ans);
  temp.pop_back();
  int upperIndex = upperBound(nums, nums[ind]);
  // for (int i = ind + 1; i < nums.size(); i++)
  // {
  //   if (nums[i] != nums[ind])
  //   {
  //     subsetSumsHelper(nums, i, temp, ans);
  //     return;
  //   }
  // }
  subsetSumsHelper(nums, upperIndex, temp, ans);
  // subsetSumsHelper(nums, nums.size(), temp, ans);
}

vector<vector<int>> subsetSums(vector<int> &nums)
{
  // your code goes here
  sort(nums.begin(), nums.end());
  vector<int> temp;
  vector<vector<int>> ans;
  subsetSumsHelper(nums, 0, temp, ans);

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
  vector<vector<int>> ans = subsetSums(nums);
  for (auto sub : ans)
  {
    for (int el : sub)
    {
      cout << el;
    }
    cout << endl;
  }
}