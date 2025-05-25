#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack2
{
  stack<int> s1;
  stack<int> s2;

public:
  void push(int x)
  {
    s1.push(x);
  }
  int pop()
  {
    if (!s2.empty())
    {
      int popEle = s2.top();
      s2.pop();
      return popEle;
    }
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }
    int popEle = s2.top();
    s2.pop();
    return popEle;
  }

  int top()
  {
    if (!s2.empty())
    {
      return s2.top();
    }
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }
    return s2.top();
  }
};

class QueueUsingStack
{
  stack<int> st1;
  stack<int> st2;

public:
  void push(int x)
  {
    while (!st1.empty())
    {
      st2.push(st1.top());
      st1.pop();
    }
    st1.push(x);
    while (!st2.empty())
    {
      st1.push(st2.top());
      st2.pop();
    }
  }

  int pop()
  {
    int popEle = st1.top();
    st1.pop();
    return popEle;
  }
  int top()
  {
    return st1.top();
  }

  bool isEmpty()
  {
    return st1.empty();
  }
};