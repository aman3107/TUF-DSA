#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int l, int mid, int r)
{
  vector<int> temp;
  int left = l;
  int right = mid + 1;
  while (left <= mid && right <= r)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left]);
      left++;
    }
    else
    {
      temp.push_back(nums[right]);
      right++;
    }
  }

  while (left <= mid)
  {
    temp.push_back(nums[left]);
    left++;
  }

  while (right <= r)
  {
    temp.push_back(nums[right]);
    right++;
  }

  for (int i = l; i <= r; i++)
  {
    nums[i] = temp[i - l];
  }
}

int countReversePairs(vector<int> &nums, int l, int mid, int r)
{
  int cnt = 0;
  int right = mid + 1;
  for (int i = l; i <= mid; i++)
  {
    while (right <= r && nums[i] > 2 * nums[right])
      right++;
    cnt += (right - (mid + 1));
  }
  return cnt;
}

int mergeSort(vector<int> &nums, int l, int r)
{
  int cnt = 0;
  if (l < r)
  {
    int mid = (l + r) / 2;
    cnt += mergeSort(nums, l, mid);
    cnt += mergeSort(nums, mid + 1, r);
    cnt += countReversePairs(nums, l, mid, r);
    merge(nums, l, mid, r);
  }
  return cnt;
}

int reversePairs(vector<int> &nums)
{
  int n = nums.size();
  return mergeSort(nums, 0, n - 1);
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

  cout << reversePairs(nums) << endl;
}
