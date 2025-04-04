#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
  int n = nums.size();
  int max = nums[n - 1];
  vector<int> ans;
  ans.push_back(nums[n - 1]);
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] > max)
    {
      ans.push_back(nums[i]);
      max = nums[i];
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;

  // TC = O(N)
  // SC = O(N)
}

vector<int> leadersBrute(vector<int> &nums)
{
  vector<int> ans;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++)
  {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] < nums[j])
      {
        leader = false;
        break;
      }
    }
    if (leader == true)
    {
      ans.push_back(nums[i]);
    }
  }
  ans.push_back(nums[n - 1]);
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
  vector<int> ans = leaders(v);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}