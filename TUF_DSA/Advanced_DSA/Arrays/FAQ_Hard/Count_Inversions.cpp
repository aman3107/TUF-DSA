#include <bits/stdc++.h>
using namespace std;

long long int mergeSort(vector<int> &nums, int low, int mid, int high)
{
  int left = low;
  int right = mid + 1;
  long long int cnt = 0;
  vector<int> temp;
  while (left <= mid && right <= high)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left]);
      left++;
    }
    else
    {
      temp.push_back(nums[right]);
      cnt += (mid - left) + 1;
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(nums[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(nums[right]);
    right++;
  }
  for (int i = low; i <= high; i++)
  {
    nums[i] = temp[i - low];
  }
  return cnt;
}

long long int merge(vector<int> &nums, int low, int high)
{
  long long int cnt = 0;
  if (low < high)
  {
    int mid = (low + high) / 2;
    cnt += merge(nums, low, mid);
    cnt += merge(nums, mid + 1, high);
    cnt += mergeSort(nums, low, mid, high);
  }
  return cnt;
}

long long int numberOfInversions(vector<int> nums)
{
  int n = nums.size();
  return merge(nums, 0, n - 1);
}

long long int numberOfInversionsBrute(vector<int> nums)
{
  int n = nums.size();
  long long int cntInversions = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] > nums[j] && i < j)
      {
        cntInversions++;
      }
    }
  }
  return cntInversions;
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
  cout << numberOfInversions(v) << endl;
}