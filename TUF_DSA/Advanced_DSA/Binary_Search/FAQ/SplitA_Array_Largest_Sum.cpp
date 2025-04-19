#include <bits/stdc++.h>
using namespace std;

int countSubArray(vector<int> &nums, int sum)
{
  int count = 1;
  int subArraySum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] + subArraySum <= sum)
    {
      subArraySum += nums[i];
    }
    else
    {
      count++;
      subArraySum = nums[i];
    }
  }
  return count;
}

int splitArray(vector<int> &nums, int k)
{
  int n = nums.size();
  int low = nums[0];
  int high = 0;
  for (int i = 0; i < n; i++)
  {
    low = max(nums[i], low);
    high += nums[i];
  }
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (countSubArray(nums, mid) > k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

int splitArrayBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  if (k > n)
  {
    return -1;
  }
  int maxElement = nums[0];
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    maxElement = max(nums[i], maxElement);
    totalSum += nums[i];
  }

  for (int i = maxElement; i < +totalSum; i++)
  {
    if (countSubArray(nums, i) == k)
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
  int m;
  cin >> m;
  cout << splitArray(nums, m) << endl;
  return 0;
}