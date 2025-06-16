#include <bits/stdc++.h>
using namespace std;

void heapify_down(vector<int> &nums, int last, int ind)
{
  int largest = ind;
  int leftInd = (2 * ind) + 1;
  int rightInd = (2 * ind) + 2;

  if (leftInd <= last && nums[leftInd] > nums[largest])
  {
    largest = leftInd;
  }
  if (rightInd <= last && nums[rightInd] > nums[largest])
  {
    largest = rightInd;
  }
  if (largest != ind)
  {
    swap(nums[largest], nums[ind]);
    heapify_down(nums, last, largest);
  }
  return;
}

void buildMaxHeap(vector<int> &nums)
{
  int n = nums.size();
  int internal_nodes = (n / 2) - 1;
  while (internal_nodes >= 0)
  {
    heapify_down(nums, n - 1, internal_nodes);
    internal_nodes--;
  }
}

void heapSort(vector<int> &nums)
{
  buildMaxHeap(nums);
  int last = nums.size() - 1;
  while (last > 0)
  {

    swap(nums[0], nums[last]);
    last--;
    if (last > 0)
    {
      heapify_down(nums, last, 0);
    }
  }
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
  heapSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}