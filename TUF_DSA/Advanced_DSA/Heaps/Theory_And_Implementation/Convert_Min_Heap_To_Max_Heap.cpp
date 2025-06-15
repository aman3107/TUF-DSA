#include <bits/stdc++.h>
using namespace std;

void heapify_down(vector<int> &arr, int ind)
{
  int parent = ind;
  int lChild = (2 * ind) + 1;
  int rChild = (2 * ind) + 2;
  if (lChild < arr.size() && arr[lChild] > arr[parent])
  {
    parent = lChild;
  }
  if (rChild < arr.size() && arr[rChild] > arr[parent])
  {
    parent = rChild;
  }
  if (parent != ind)
  {
    swap(arr[parent], arr[ind]);
    heapify_down(arr, parent);
  }
  return;
}

vector<int> minToMaxHeap(vector<int> nums)
{
  int n = (nums.size() / 2) - 1;
  while (n >= 0)
  {
    heapify_down(nums, n);
    n--;
  }
  return nums;
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
  vector<int> ans = minToMaxHeap(arr);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}