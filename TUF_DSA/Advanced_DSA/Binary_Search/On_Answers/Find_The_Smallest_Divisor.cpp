#include <bits/stdc++.h>
using namespace std;

int largestElementBinary(vector<int> &nums)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int max_Element = INT_MIN;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[low] <= nums[mid])
    {
      max_Element = max(max_Element, nums[mid]);
      low = mid + 1;
    }
    else
    {
      max_Element = max(max_Element, nums[high]);
      high = mid - 1;
    }
  }
  return max_Element;
}

int largestElement(vector<int> &nums)
{
  int n = nums.size();
  int getMax = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > getMax)
    {
      getMax = nums[i];
    }
  }
  return getMax;
}

int smallestDivisor(vector<int> &nums, int limit)
{

  int n = nums.size();
  int low = 1;
  int high = largestElement(nums);
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)nums[i] / (double)mid);
    }
    if (sum <= limit)
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

int smallestDivisorBrute(vector<int> &nums, int limit)
{
  int n = nums.size();

  int max_Element = largestElement(nums);
  for (int d = 1; d <= max_Element; d++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)nums[i] / (double)d);
    }
    if (sum <= limit)
    {
      return d;
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
  cout << smallestDivisorBrute(nums, limit);
}