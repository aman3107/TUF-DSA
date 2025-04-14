#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == k)
    {
      return true;
    }
    if (nums[low] == nums[mid] && nums[mid] == nums[high])
    {
      low = low + 1;
      high = high - 1;
      continue;
    }
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
  return false;
}

int searchLinear(vector<int> &nums, int k)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (k == nums[i])
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
  cout << searchInARotatedSortedArrayII(v, target) << endl;
}