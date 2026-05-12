#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
  int n = nums.size();
  if (n == 1 || nums[0] != nums[1])
    return nums[0];
  if (nums[n - 1] != nums[n - 2])
    return nums[n - 1];

  int low = 1;
  int high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
    {
      return nums[mid];
    }
    else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int findKRotation(vector<int> &nums)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int ans = INT_MAX;
  int index = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[low] <= nums[high])
    {
      if (nums[low] < ans)
      {
        ans = nums[low];
        index = low;
      }
      break;
    }
    if (nums[low] <= nums[mid])
    {
      if (nums[low] < ans)
      {
        ans = nums[low];
        index = low;
      }
      low = mid + 1;
    }
    else
    {
      if (nums[mid] < ans)
      {
        ans = nums[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
}

int findMin(vector<int> &arr)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    else
    {
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}

bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == k)
      return mid;

    // handling duplictes
    if (nums[low] == nums[mid] && nums[mid] == nums[high])
    {
      low = low + 1;
      high = high - 1;
      continue;
    }

    // left part sorted;
    if (nums[low] <= nums[mid])
    {
      // if in range of low and high
      if (nums[low] <= k && k <= nums[mid])
      {
        high = mid - 1;
      }
      // not in range of low and high
      else
      {
        low = mid + 1;
      }
    }

    // right sorted
    else
    {
      // range of mid and high
      if (nums[mid] <= k && k <= nums[high])
      {
        low = mid + 1;
      }
      // not in range of mid and high
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int search(vector<int> &nums, int k)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == k)
      return mid;
    if (nums[low] <= nums[mid])
    {
      if (nums[low] <= k && k <= nums[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (nums[mid] <= k && k <= nums[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int findLast(vector<int> &nums, int x)
{
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int last = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == x)
    {
      last = mid;
      left = mid + 1;
    }
    else if (nums[mid] > x)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return last;
}

int findFirst(vector<int> &nums, int x)
{
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int first = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == x)
    {
      first = mid;
      right = mid - 1;
    }
    else if (nums[mid] < x)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return first;
}

vector<int> searchRange(vector<int> &nums, int target)
{
  return {findFirst(nums, target), findLast(nums, target)};
}

int findFloor(vector<int> &nums, int x)
{
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int floor = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= x)
    {
      floor = nums[mid];
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return floor;
}

int findCeil(vector<int> &nums, int x)
{
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int ceil = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] >= x)
    {
      ceil = nums[mid];
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return ceil;
}

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
  int floor = findFloor(nums, x);
  int ceil = findCeil(nums, x);
  return {floor, ceil};
}

int searchInsert(vector<int> &nums, int target)
{
  int n = nums.size();
  int ans = n;
  int left = 0;
  int right = n - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] >= target)
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
  cout << searchInsert(nums, tar);
}