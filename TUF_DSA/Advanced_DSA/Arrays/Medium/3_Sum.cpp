#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
  vector<vector<int>> ans;
  int n = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum < 0)
      {
        j++;
      }
      else if (sum > 0)
      {
        k--;
      }
      else
      {
        vector<int> temp = {nums[i], nums[j], nums[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && nums[j] == nums[j - 1])
          j++;
        while (j < k && nums[k] == nums[k + 1])
          k--;
      }
    }
  }
  return ans;
}

vector<vector<int>> threeSumBetter(vector<int> &nums)
{
  set<vector<int>> triplets;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    unordered_set<int> hashset;
    for (int j = i + 1; j < n; j++)
    {
      int third = -(nums[i] + nums[j]);
      if (hashset.find(third) != hashset.end())
      {
        vector<int> temp = {nums[i], nums[j], third};
        sort(temp.begin(), temp.end());
        triplets.insert(temp);
      }
      hashset.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(triplets.begin(), triplets.end());
  return ans;
}

vector<vector<int>> threeSumBrute(vector<int> &nums)
{
  set<vector<int>> triplets;
  int n = nums.size();
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (nums[i] + nums[j] + nums[k] == 0)
        {
          vector<int> temp;
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
          sort(temp.begin(), temp.end());
          triplets.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(triplets.begin(), triplets.end());
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }
  vector<vector<int>> ans = threeSum(v);
  for (auto a : ans)
  {
    for (auto i : a)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}