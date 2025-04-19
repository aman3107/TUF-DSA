#include <bits/stdc++.h>
using namespace std;

int findPeakElementBrute(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1]))
    {
      return i;
    }
  }
  return -1;
}

int findPeakElement(vector<int> &arr)
{
  int n = arr.size();
  if (n <= 1)
  {
    return 0;
  }
  if (arr[0] > arr[1])
    return 0;
  if (arr[n - 1] > arr[n - 2])
    return n - 1;

  int low = 1;
  int high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
      return mid;
    }
    else if (arr[mid] > arr[mid - 1])
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
  cout << findPeakElementBrute(nums) << endl;
  return 0;
}