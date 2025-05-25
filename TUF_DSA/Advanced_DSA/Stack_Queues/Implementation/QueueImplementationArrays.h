#include <bits/stdc++.h>
using namespace std;

class QueueImple
{
private:
  int *arr;
  int start;
  int end;
  int capacity;
  int currSize;

public:
  QueueImple(int size)
  {
    arr = new int[size];
    start = -1;
    end = -1;
    capacity = size;
    currSize = 0;
  }

  ~QueueImple()
  {
    delete[] arr;
  }

  bool isEmpty()
  {
    return currSize == 0;
  }

  void push(int x)
  {
    if (currSize == capacity)
    {
      return;
    }
    if (start == -1 && end == -1)
    {
      start++;
      end++;
    }
    else
    {
      end = (end + 1) % capacity;
    }
    arr[end] = x;
    currSize++;
  }
  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    int popEle = arr[start];
    if (currSize == 1)
    {
      start = end = -1;
    }
    else
    {
      start = (start + 1) % capacity;
    }
    currSize--;
    return popEle;
  }

  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return arr[start];
  }

  int size()
  {
    return currSize;
  }
};