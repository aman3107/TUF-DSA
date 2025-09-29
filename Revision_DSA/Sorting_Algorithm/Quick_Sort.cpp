#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int pivotIndex = 0;
  for (int i = low + 1; i <= high; i++)
  {
    if (pivot >= arr[i])
    {
      pivotIndex++;
    }
  }
  int partitionIndex = low + pivotIndex;
  arr[low] = arr[partitionIndex];
  arr[partitionIndex] = pivot;
  int l = low;
  int r = high;
  while (l < partitionIndex && partitionIndex < r)
  {
    if (arr[l] <= pivot)
    {
      l++;
    }
    else if (arr[r] > pivot)
    {
      r--;
    }
    else
    {
      int temp = arr[l];
      arr[l] = arr[r];
      arr[r] = temp;
      l++;
      r--;
    }
  }
  return partitionIndex;
}

void helper(vector<int> &arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int pivotInd = findPivot(arr, l, r);
  helper(arr, l, pivotInd - 1);
  helper(arr, pivotInd + 1, r);
}

void quickSort(vector<int> &arr)
{
  int n = arr.size();
  helper(arr, 0, n - 1);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  quickSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}