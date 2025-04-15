#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
  int n = nums.size();
  if (n == 1)
  {
    return nums[0];
  }
  if (nums[0] != nums[1])
    return nums[0];
  if (nums[n - 1] != nums[n - 2])
  {
    return nums[n - 1];
  }
  int low = 1;
  int high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
    {
      return nums[mid];
    }
    if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
}

int singleNonDuplicateBruteXOR(vector<int> &nums)
{
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = ans ^ nums[i];
  }
  return ans;
}

int singleNonDuplicateBrute(vector<int> &nums)
{

  int n = nums.size();
  if (n == 1)
  {
    return nums[0];
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (nums[i] != nums[i + 1])
      {
        return nums[i];
      }
    }
    else if (i == n - 1)
    {
      if (nums[i - 1] != nums[i])
      {
        return nums[i];
      }
    }
    else
    {
      if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
      {
        return nums[i];
      }
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
  cout << singleNonDuplicateBruteXOR(v) << endl;
}