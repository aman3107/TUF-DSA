#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n; j++)
    {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      int k = j + 1;
      int l = n - 1;
      while (k < l)
      {
        long long int sum = nums[i] + nums[j] + nums[k] + nums[l];
        if (sum < target)
        {
          k++;
        }
        else if (sum > target)
        {
          l--;
        }
        else
        {
          ans.push_back({nums[i], nums[j], nums[k], nums[l]});
          k++;
          l--;
          while (k < l && nums[k] == nums[k - 1])
            k++;
          while (k < l && nums[l] == nums[l + 1])
            l--;
        }
      }
    }
  }
  return ans;
}

vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
  set<vector<int>> st;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      set<int> hashset;
      for (int k = j + 1; k < n; k++)
      {
        int fourth = target - (nums[i] + nums[j] + nums[k]);
        if (hashset.find(fourth) != hashset.end())
        {
          vector<int> temp = {nums[i], nums[j], nums[k], fourth};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(nums[k]);
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
{

  set<vector<int>> st;
  int n = nums.size();
  for (int i = 0; i < n - 3; i++)
  {
    for (int j = i + 1; j < n - 2; j++)
    {
      for (int k = j + 1; k < n - 1; k++)
      {
        for (int l = k + 1; l < n; l++)
        {
          int sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum == target)
          {
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
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
  int target;
  cin >> target;
  vector<vector<int>> ans = fourSum(v, target);
  for (auto a : ans)
  {
    for (auto i : a)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}