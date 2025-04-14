#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int ind = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= target)
    {
      ind = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ind;
}

int upperBound(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int ind = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] > target)
    {
      ind = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ind;
}

int LastOccurrence(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int last = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
      last = mid;
      low = mid + 1;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return last;
}

int firstOccurrence(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int first = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
      first = mid;
      high = mid - 1;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return first;
}

vector<int> searchRangeBound(vector<int> &nums, int target)
{
  int first = lowerBound(nums, target);
  if (first == nums.size() || nums[first] != target)
  {
    return {-1, -1};
  }
  int last = upperBound(nums, target);
  return {first, last - 1};
}

vector<int> searchRange(vector<int> &nums, int target)
{

  int firstOccur = firstOccurrence(nums, target);
  if (firstOccur == -1)
  {
    return {-1, -1};
  }
  int lastOccur = LastOccurrence(nums, target);
  return {firstOccur, lastOccur};
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
  vector<int> ans = searchRangeBound(v, target);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
}