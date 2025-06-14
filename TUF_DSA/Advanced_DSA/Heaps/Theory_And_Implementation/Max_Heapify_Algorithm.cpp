#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
  int c = a;
  a = b;
  b = c;
}

void heapify_down(vector<int> &arr, int ind)
{
  int largest = ind;
  int lChild = (2 * ind) + 1;
  int rChild = (2 * ind) + 2;
  if (lChild < arr.size() && arr[largest] < arr[lChild])
  {
    largest = lChild;
  }
  if (rChild < arr.size() && arr[largest] < arr[rChild])
  {
    largest = rChild;
  }
  if (largest != ind)
  {
    swap(arr[ind], arr[largest]);
    heapify_down(arr, largest);
  }
}

void heapify_up(vector<int> &arr, int ind)
{
  int parent = (ind - 1) / 2;
  if (ind > 0)
  {
    if (arr[ind] > arr[parent])
    {
      swap(arr[ind], arr[parent]);
      heapify_up(arr, parent);
    }
  }
}

void heapify(vector<int> &nums, int ind, int val)
{
  if (nums[ind] > val)
  {
    nums[ind] = val;
    heapify_down(nums, ind);
  }
  else
  {
    nums[ind] = val;
    heapify_up(nums, ind);
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
  cout << "Enter index and value :" << endl;
  int ind;
  int val;
  cin >> ind >> val;
  heapify(arr, ind, val);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}