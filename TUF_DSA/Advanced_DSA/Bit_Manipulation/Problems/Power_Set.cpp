#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums)
{
  int subsets = 1 << nums.size();
  vector<vector<int>> ans;
  for (int i = 0; i < subsets; i++)
  {
    vector<int> temp;
    for (int j = 0; j < nums.size(); j++)
    {
      if (i & (1 << j))
      {
        temp.push_back(nums[j]);
      }
    }
    ans.push_back(temp);
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
    int data;
    cin >> data;
    v.push_back(data);
  }
  vector<vector<int>> ans = powerSet(v);
  for (auto it : ans)
  {
    for (auto i : it)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}