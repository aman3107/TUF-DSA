#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int si, int ei)
{
  int countSmallerElements = 0;
  int partitionNum = arr[si];
  for (int i = si + 1; i <= ei; i++)
  {
    if (arr[i] <= partitionNum)
    {
      countSmallerElements++;
    }
  }
  int partitionIndex = si + countSmallerElements;
  arr[si] = arr[partitionIndex];
  arr[partitionIndex] = partitionNum;
  int i = si;
  int j = ei;
  while (i < partitionIndex && j > partitionIndex)
  {
    if (arr[i] <= partitionNum)
    {
      i++;
    }
    else if (arr[j] > partitionNum)
    {
      j--;
    }
    else
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  return partitionIndex;
}

void quick(vector<int> &arr, int si, int ei)
{
  if (si >= ei)
  {
    return;
  }
  int c = partition(arr, si, ei);
  quick(arr, si, c - 1);
  quick(arr, c + 1, ei);
}

vector<int> quickSort(vector<int> &nums)
{
  if (nums.size() == 0 || nums.size() == 1)
  {
    return nums;
  }
  quick(nums, 0, nums.size() - 1);
  return nums;

  // TC = O(NlogN)
  // SC =  O(1)
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }
  vector<int> ans = quickSort(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}