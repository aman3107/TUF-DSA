#include <bits/stdc++.h>
using namespace std;

bool comparator(const vector<int> &a, const vector<int> &b)
{
  return a[0] < b[0];
}

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<vector<int>> elementIndex;
  for (int i = 0; i < nums.size(); i++)
  {
    elementIndex.push_back({nums[i], i});
  }

  sort(elementIndex.begin(), elementIndex.end(), comparator);
  vector<int> ans;
  int left = 0;
  int right = nums.size() - 1;
  while (left < right)
  {
    int sum = elementIndex[left][0] + elementIndex[right][0];
    if (sum == target)
    {
      ans.push_back(elementIndex[left][1]);
      ans.push_back(elementIndex[right][1]);
      return ans;
    }
    else if (sum > target)
    {
      right--;
    }
    else
    {
      left++;
    }
  }
  ans.push_back(-1);
  ans.push_back(-1);
  return ans;

  // TC = O(NlogN)
  // SC = O(N)
}

vector<int> twoSumBetter(vector<int> &nums, int target)
{
  unordered_map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
    int num = nums[i];
    int needed = target - num;
    if (mp.find(needed) != mp.end())
    {
      ans.push_back(mp[needed]);
      ans.push_back(i);
      return ans;
    }
    mp[num] = i;
  }
  return ans;

  // TC = O(N) or O(N2) in worst case
  // SC = O(N)
}

vector<int> twoSumBrute(vector<int> &nums, int target)
{
  vector<int> ans;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
  }
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
  vector<int> ans = twoSum(v, target);
  for (auto i : ans)
  {
    cout << i << " ";
  }
}