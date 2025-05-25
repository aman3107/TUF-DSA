#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *next;
  int data;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

class QueueLL
{
  Node *start;
  Node *end;
  int currSize;

public:
  QueueLL()
  {
    start = nullptr;
    end = nullptr;
    currSize = 0;
  }

  ~QueueLL()
  {
    delete start;
    delete end;
  }

  bool isEmpty()
  {
    return currSize == 0;
  }

  void push(int x)
  {
    Node *newNode = new Node(x);
    if (start == nullptr && end == nullptr)
    {
      start = newNode;
      end = newNode;
    }
    else
    {
      end->next = newNode;
      end = newNode;
    }
    currSize++;
  }

  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = start;
    if (currSize == 1)
    {
      start = nullptr;
      end = nullptr;
    }
    else
    {
      start = start->next;
    }

    int popEle = temp->data;
    delete temp;
    currSize--;
    return popEle;
  }

  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return start->data;
  }
  int size()
  {
    return currSize == 0;
  }
};