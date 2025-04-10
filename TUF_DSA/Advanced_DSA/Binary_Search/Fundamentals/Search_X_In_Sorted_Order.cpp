#include <bits/stdc++.h>
using namespace std;

int searchIterativeHelper(vector<int> &nums, int low, int high, int target)
{
  if (low > high)
  {
    return -1;
  }
  int ind;
  int mid = low + (high - low) / 2;
  if (nums[mid] == target)
  {
    ind = mid;
  }
  else if (nums[mid] > target)
  {
    ind = searchIterativeHelper(nums, low, mid - 1, target);
  }
  else
  {
    ind = searchIterativeHelper(nums, mid + 1, high, target);
  }
  return ind;
}

int searchIterative(vector<int> &nums, int target)
{
  int n = nums.size() - 1;
  return searchIterativeHelper(nums, 0, n, target);
}

int search(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int mid = low + (high - low) / 2;
  while (low <= high)
  {
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
    mid = low + (high - low) / 2;
  }
  return -1;
}

int searchBrute(vector<int> &nums, int target)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == target)
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
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }
  int target;
  cin >> target;
  cout << searchIterative(v, target) << endl;
}