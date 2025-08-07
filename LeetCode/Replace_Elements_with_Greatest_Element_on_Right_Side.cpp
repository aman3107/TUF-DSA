#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> replaceElements(vector<int> &nums)
  {
    vector<int> ans;
    int n = nums.size();
    int maxi = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      ans.push_back(maxi);
      maxi = max(maxi, nums[i]);
    }
    reverse(ans.begin(), ans.end());
    ans.push_back(-1);
    return ans;
  }
};