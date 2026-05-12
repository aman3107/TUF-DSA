#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int x)
{
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int ans = n;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] > x)
    {
      ans = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return ans;
}

int lowerBound(vector<int> &nums, int x)
{
  int n = nums.size();
  int lowerBound = n;
  int left = 0;
  int right = n - 1;
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (nums[mid] >= x)
    {
      lowerBound = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return lowerBound;
}

int search(vector<int> &nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int searchBrute(vector<int> &nums, int target)
{
  for (int i = 0; i < nums.size(); i++)
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
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums.push_back(data);
  }
  int tar;
  cin >> tar;
  cout << searchBrute(nums, tar);
}