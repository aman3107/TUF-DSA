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
  int root = ind;
  int lChild = (2 * ind) + 1;
  int rChild = (2 * ind) + 2;
  if (lChild < arr.size() && arr[lChild] < arr[root])
  {
    root = lChild;
  }
  if (rChild < arr.size() && arr[rChild] < arr[root])
  {
    root = rChild;
  }
  if (root != ind)
  {
    swap(arr[root], arr[ind]);
    heapify_down(arr, root);
  }
}

void heapify_up(vector<int> &arr, int ind)
{
  int parent = (ind - 1) / 2;
  if (ind > 0)
  {
    if (arr[parent] > arr[ind])
    {
      swap(arr[parent], arr[ind]);
      heapify_up(arr, parent);
    }
  }
}

void heapify(vector<int> &arr, int ind, int val)
{
  if (arr[ind] > val)
  {
    arr[ind] = val;
    heapify_up(arr, ind);
  }
  else
  {
    arr[ind] = val;
    heapify_down(arr, ind);
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