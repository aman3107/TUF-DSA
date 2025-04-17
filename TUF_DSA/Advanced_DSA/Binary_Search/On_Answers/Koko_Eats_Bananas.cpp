#include <bits/stdc++.h>
using namespace std;

int getMaxElement(vector<int> &nums)
{
  int n = nums.size();
  int maxElement = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    maxElement = max(nums[i], maxElement);
  }
  return maxElement;
}

long long calculateTotalHours(vector<int> &nums, int hourly)
{
  long long totalHours = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalHours += ceil((double)nums[i] / (double)hourly);
  }
  return totalHours;
}

int minimumRateToEatBananas(vector<int> nums, int h)
{
  int n = nums.size();
  int low = 1;
  int high = getMaxElement(nums);
  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    long long sum = calculateTotalHours(nums, mid);
    if (sum <= h)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int minimumRateToEatBananasBrute(vector<int> nums, int h)
{
  int n = nums.size();
  int maxElement = getMaxElement(nums);
  for (int i = 1; i <= maxElement; i++)
  {
    long long sum = calculateTotalHours(nums, i);
    if (sum <= h)
    {
      return i;
    }
  }
  return -1;
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
  int limit;
  cin >> limit;
  cout << minimumRateToEatBananasBrute(nums, limit);
}