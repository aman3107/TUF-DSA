#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int low, int mid, int high)
{
  int cntPairs = 0;
  int right = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (right <= high && nums[i] > 2 * nums[right])
    {
      right++;
    }
    cntPairs += (right - (mid + 1));
  }
  return cntPairs;
}

void merge(vector<int> &nums, int low, int mid, int high)
{
  int left = low;
  int right = mid + 1;
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
}

int mergeSort(vector<int> &nums, int low, int high)
{
  int cnt = 0;
  if (low >= high)
  {
    return cnt;
  }
  int mid = (low + high) / 2;
  cnt += mergeSort(nums, low, mid);
  cnt += mergeSort(nums, mid + 1, high);
  cnt += countPairs(nums, low, mid, high);
  merge(nums, low, mid, high);
  return cnt;
}

int reversePairs(vector<int> &nums)
{
  int n = nums.size();
  return mergeSort(nums, 0, n - 1);
}

int reversePairsBrute(vector<int> &nums)
{
  int n = nums.size();
  int cntReversePair = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] > (2 * nums[j]) && i < j)
      {
        cntReversePair++;
      }
    }
  }
  return cntReversePair;
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
  cout << reversePairs(v) << endl;
}