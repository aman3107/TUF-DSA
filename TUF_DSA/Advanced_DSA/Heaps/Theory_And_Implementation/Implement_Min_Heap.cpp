#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<int> arr;
  int count;

  void swap(int &a, int &b)
  {
    int c = a;
    a = b;
    b = c;
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
    return;
  }
  void heapify_down(vector<int> &arr, int ind)
  {
    int parent = ind;
    int lChild = (2 * ind) + 1;
    int rChild = (2 * ind) + 2;
    if (lChild < arr.size() && arr[lChild] < arr[parent])
    {
      parent = lChild;
    }
    if (rChild < arr.size() && arr[rChild] < arr[parent])
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

public:
  void initializeHeap()
  {
    arr.clear();
    count = 0;
  }

  void insert(int key)
  {
    arr.push_back(key);
    heapify_up(arr, count);
    count++;
  }

  void changeKey(int index, int new_val)
  {
    if (arr[index] > new_val)
    {
      arr[index] = new_val;
      heapify_up(arr, index);
    }
    else
    {
      arr[index] = new_val;
      heapify_down(arr, new_val);
    }
  }

  void extractMin()
  {
    swap(arr[0], arr[count - 1]);
    arr.pop_back();
    count--;
    heapify_down(arr, 0);
  }

  bool isEmpty()
  {
    return count == 0;
  }

  int getMin()
  {
    return arr[0];
  }

  int heapSize()
  {
    return count;
  }
};