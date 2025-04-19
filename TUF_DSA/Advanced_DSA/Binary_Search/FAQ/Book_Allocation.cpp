#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &nums, int pages)
{
  int students = 1;
  int studentsPages = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] + studentsPages <= pages)
    {
      studentsPages += nums[i];
    }
    else
    {
      students++;
      studentsPages = nums[i];
    }
  }
  return students;
}

int findPages(vector<int> &nums, int m)
{
  int n = nums.size();
  if (m > n)
  {
    return -1;
  }
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
    if (countStudents(nums, mid) > m)
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

int findPagesBrute(vector<int> &nums, int m)
{
  int n = nums.size();
  if (m > n)
  {
    return -1;
  }
  int minIndex = nums[0];
  int maxIndex = 0;
  for (int i = 0; i < n; i++)
  {
    minIndex = max(nums[i], minIndex);
    maxIndex += nums[i];
  }
  for (int i = minIndex; i <= maxIndex; i++)
  {
    if (countStudents(nums, i) == m)
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
  cout << findPages(nums, m) << endl;
  return 0;
}