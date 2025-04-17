#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &nums)
{
  int maxElement = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    maxElement = max(maxElement, nums[i]);
  }
  return maxElement;
}

int getMin(vector<int> &nums)
{
  int minElement = INT_MAX;
  for (int i = 0; i < nums.size(); i++)
  {
    minElement = min(minElement, nums[i]);
  }
  return minElement;
}

int possibleWays(vector<int> &nums, int k, int m, int day)
{
  int cnt = 0;
  int noOfB = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (nums[i] <= day)
    {
      cnt++;
    }
    else
    {
      noOfB += (cnt / k);
      cnt = 0;
    }
  }
  noOfB += (cnt / k);
  return noOfB >= m;
}

int roseGardenBrute(int n, vector<int> nums, int k, int m)
{
  if (n < k * m)
  {
    return -1;
  }
  int maxElement = getMax(nums);
  int minElement = getMin(nums);
  for (int i = minElement; i <= maxElement; i++)
  {
    if (possibleWays(nums, k, m, i))
    {
      return i;
    }
  }
  return -1;
}

int roseGarden(int n, vector<int> nums, int k, int m)
{
  long long val = k * 1ll * m * 1ll;
  if (n < val)
  {
    return -1;
  }
  int low = getMin(nums);
  int high = getMax(nums);
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (possibleWays(nums, k, m, mid))
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
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

  int k, m;
  cin >> k >> m;
  cout << roseGarden(n, nums, k, m) << endl;
}