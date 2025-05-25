#include <bits/stdc++.h>
using namespace std;

class stackImple
{
  int *arr;
  int ind;
  int capacity;

public:
  stackImple(int size)
  {
    arr = new int[size];
    ind = -1;
    capacity = size;
  }
  bool isEmpty()
  {
    return ind == -1;
  }
  void push(int data)
  {
    if (ind >= capacity - 1)
    {
      cout << "Stack is full " << endl;
      return;
    }
    ind++;
    arr[ind] = data;
  }
  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    int popEle = arr[ind];
    ind--;
    return popEle;
  }
  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return arr[ind];
  }
  int size()
  {
    if (isEmpty())
    {
      return -1;
    }
    return ind + 1;
  }
};