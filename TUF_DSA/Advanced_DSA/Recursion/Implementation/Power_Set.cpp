#include <bits/stdc++.h>
using namespace std;

void powerSetHelper(vector<int> &nums, vector<int> &temp, int ind, int n, vector<vector<int>> &ans)
{
  if (ind == n)
  {
    ans.push_back(temp);
    return;
  }
  temp.push_back(nums[ind]);
  powerSetHelper(nums, temp, ind + 1, n, ans);
  temp.pop_back();
  powerSetHelper(nums, temp, ind + 1, n, ans);
}

vector<vector<int>> powerSet(vector<int> &nums)
{
  // your code goes here
  int n = nums.size();
  vector<vector<int>> ans;
  vector<int> temp;
  powerSetHelper(nums, temp, 0, n, ans);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    arr.push_back(val);
  }

  vector<vector<int>> ans = powerSet(arr);
  for (auto subArray : ans)
  {
    for (int val : subArray)
    {
      cout << val;
    }
    cout << endl;
  }
}