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
}

void buildMinHeap(vector<int> &arr)
{
  int internal_nodes = (arr.size() / 2) - 1;
  while (internal_nodes >= 0)
  {
    heapify_down(arr, internal_nodes);
    internal_nodes--;
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
  buildMinHeap(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}