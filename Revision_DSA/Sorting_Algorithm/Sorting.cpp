#include <bits/stdc++.h>
using namespace std;

int partitionHelper(vector<int> &nums, int si, int ei)
{
  int partNum = nums[si];
  int count = 0;
  for (int i = si + 1; i <= ei; i++)
  {
    if (partNum >= nums[i])
    {
      count++;
    }
  }
  int partIndex = si + count;
  nums[si] = nums[partIndex];
  nums[partIndex] = partNum;

  int l = si;
  int r = ei;
  while (l < partIndex && r > partIndex)
  {
    if (nums[l] <= partNum)
    {
      l++;
    }
    else if (nums[r] > partNum)
    {
      r--;
    }
    else
    {
      int temp = nums[l];
      nums[l] = nums[r];
      nums[r] = temp;
      l++;
      r--;
    }
  }
  return partIndex;
}

void quickHelper(vector<int> &nums, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int partIndex = partitionHelper(nums, l, r);
  quickHelper(nums, l, partIndex - 1);
  quickHelper(nums, partIndex + 1, r);
}

vector<int> quickSort(vector<int> &nums)
{
  quickHelper(nums, 0, nums.size() - 1);
  return nums;
}

void merge(vector<int> &nums, int l, int mid, int r)
{
  int left = l;
  int right = mid + 1;
  vector<int> temp;
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

void mergeHelper(vector<int> &nums, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int mid = (l + r) / 2;
  mergeHelper(nums, l, mid);
  mergeHelper(nums, mid + 1, r);
  merge(nums, l, mid, r);
}

vector<int> mergeSort(vector<int> &nums)
{
  mergeHelper(nums, 0, nums.size() - 1);
  return nums;
}

vector<int> insertionSort(vector<int> &nums)
{
  for (int i = 1; i < nums.size(); i++)
  {
    int puc = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > puc)
    {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = puc;
  }
  return nums;
}

vector<int> bubbleSort(vector<int> &nums)
{
  for (int i = 0; i < nums.size() - 1; i++)
  {
    bool swaped = false;
    for (int j = 1; j < nums.size() - i; j++)
    {
      if (nums[j - 1] > nums[j])
      {
        swaped = true;
        swap(nums[j - 1], nums[j]);
      }
    }
    if (!swaped)
    {
      break;
    }
  }
  return nums;
}

vector<int> selectionSort(vector<int> &nums)
{
  for (int i = 0; i < nums.size() - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[j] < nums[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
      swap(nums[i], nums[minIndex]);
  }
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
  vector<int> ans = insertionSort(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}