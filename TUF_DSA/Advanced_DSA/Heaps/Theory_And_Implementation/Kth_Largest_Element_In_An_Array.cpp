#include <bits/stdc++.h>
using namespace std;

// ---------- Brute Start ------------

void heapify_down(vector<int> &arr, int last, int ind)
{
  int smallest = ind;
  int leftInd = (2 * ind) + 1;
  int rightInd = (2 * ind) + 2;

  if (leftInd <= last && arr[leftInd] < arr[smallest])
  {
    smallest = leftInd;
  }
  if (rightInd <= last && arr[rightInd] < arr[smallest])
  {
    smallest = rightInd;
  }
  if (smallest != ind)
  {
    swap(arr[smallest], arr[ind]);
    heapify_down(arr, last, smallest);
  }
}

void buildMinHeap(vector<int> &arr)
{
  int n = arr.size();
  int interna_nodes = (n / 2) - 1;
  while (interna_nodes >= 0)
  {
    heapify_down(arr, n - 1, interna_nodes);
    interna_nodes--;
  }
  return;
}

void heapSort(vector<int> &arr)
{
  buildMinHeap(arr);
  int last = arr.size() - 1;
  while (last > 0)
  {
    swap(arr[0], arr[last]);
    last--;
    if (last > 0)
    {
      heapify_down(arr, last, 0);
    }
  }
}

int kthLargestElementBrute(vector<int> &nums, int k)
{
  heapSort(nums);
  cout << endl;
  return nums[k - 1];
}

// ---------- Brute End ------------

//------------ Better Start -------------

int kthLargestElementBetter(vector<int> &nums, int k)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  int n = nums.size();
  for (int i = 0; i < k; i++)
  {
    pq.push(nums[i]);
  }
  for (int i = k; i < n; i++)
  {
    if (nums[i] > pq.top())
    {
      pq.pop();
      pq.push(nums[i]);
    }
  }
  return pq.top();
}

// ---------- Better End -----------

int randomIndex(int &left, int &right)
{
  int len = right - left + 1;
  return (rand() % len) + left;
}

int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right)
{
  int pivot = nums[pivotIndex];
  swap(nums[left], nums[pivotIndex]);
  int ind = left + 1;
  for (int i = left + 1; i <= right; i++)
  {
    if (nums[i] > pivot)
    {
      swap(nums[ind], nums[i]);
      ind++;
    }
  }
  swap(nums[left], nums[ind - 1]);
  return ind - 1;
}

int kthLargestElement(vector<int> &nums, int k)
{
  int l = 0;
  int r = nums.size() - 1;
  while (true)
  {
    int pivotIndex = randomIndex(l, r);
    pivotIndex = partitionAndReturnIndex(nums, pivotIndex, l, r);
    if (pivotIndex == k - 1)
    {
      return nums[pivotIndex];
    }
    else if (pivotIndex > k - 1)
    {
      r = pivotIndex - 1;
    }
    else
    {
      l = pivotIndex + 1;
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
  cout << "Enter value of k " << endl;
  int k;
  cin >> k;
  cout << kthLargestElement(arr, k) << endl;
  return 0;
}