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

class StackLL
{
  Node *head;
  int currSize;

public:
  StackLL()
  {
    head = nullptr;
    currSize = 0;
  }

  ~StackLL()
  {
    delete head;
  }

  bool isEmpty()
  {
    return currSize == 0;
  }

  void push(int x)
  {
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    currSize++;
  }
  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = head;
    int popEle = head->data;
    head = head->next;
    currSize--;
    delete temp;
    return popEle;
  }

  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return head->data;
  }
  int size()
  {
    return currSize;
  }
};