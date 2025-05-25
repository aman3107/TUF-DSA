#include <bits/stdc++.h>
using namespace std;

class StackImpleDynamic
{
private:
  int *arr;
  int topIndex;
  int capacity;

public:
  StackImpleDynamic()
  {
    arr = new int[5];
    topIndex = -1;
    capacity = 5;
  }
  ~StackImpleDynamic()
  {
    delete[] arr;
  }
  bool isEmpty()
  {
    return topIndex == -1;
  }
  void push(int data)
  {
    if (topIndex >= capacity - 1)
    {
      int *newArr = new int[2 * capacity];
      for (int i = 0; i < capacity; i++)
      {
        newArr[i] = arr[i];
      }
      capacity = 2 * capacity;
      delete[] arr;
      arr = newArr;
    }
    topIndex++;
    arr[topIndex] = data;
  }

  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    int popEle = arr[topIndex];
    topIndex--;
    return popEle;
  }
  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return arr[topIndex];
  }
  int size()
  {
    if (isEmpty())
    {
      return -1;
    }
    return topIndex + 1;
  }
};