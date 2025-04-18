#include <bits/stdc++.h>
using namespace std;

bool possibleDistance(vector<int> nums, int k, int minDist)
{
  int cnt = 1;
  int n = nums.size();
  int left = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] - left >= minDist)
    {
      cnt++;
      left = nums[i];
    }
    if (cnt >= k)
    {
      return true;
    }
  }
  return false;
}

int aggressiveCows(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int low = 1;
  int high = nums[n - 1] - nums[0];
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (possibleDistance(nums, k, mid))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return high;
}

int aggressiveCowsBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int limit = nums[n - 1] - nums[0];

  for (int i = 1; i <= limit; i++)
  {
    if (!possibleDistance(nums, k, i))
    {
      return i - 1;
    }
  }
  return limit;
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
  cout << aggressiveCows(nums, k) << endl;
}