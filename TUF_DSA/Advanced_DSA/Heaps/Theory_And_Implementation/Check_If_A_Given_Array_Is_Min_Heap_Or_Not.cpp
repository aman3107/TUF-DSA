#include <bits/stdc++.h>
using namespace std;

bool heapify_down(vector<int> &arr, int ind)
{
  int parent = ind;
  int lChild = (2 * ind) + 1;
  int rChild = (2 * ind) + 2;

  if (lChild < arr.size() && arr[lChild] < arr[parent])
  {
    return false;
  }
  if (rChild < arr.size() && arr[rChild] < arr[parent])
  {
    return false;
  }
  return true;
}

bool isHeap(vector<int> &nums)
{
  int n = (nums.size() / 2) - 1;
  while (n >= 0)
  {
    if (!heapify_down(nums, n))
    {
      return false;
    }
    n--;
  }
  return true;
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
  cout << isHeap(arr);
}