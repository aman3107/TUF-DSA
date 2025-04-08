#include <bits/stdc++.h>
using namespace std;

int longestSubarrayBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  int longest = 0;
  for (int i = 0; i < n; i++)
  {
    int currentSum = 0;
    for (int j = i; j < n; j++)
    {
      currentSum += nums[j];
      if (currentSum == k)
      {
        longest = max(longest, (j - i) + 1);
      }
    }
  }
  return longest;
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
  int k;
  cin >> k;
  cout << longestSubarrayBrute(v, k) << endl;
}