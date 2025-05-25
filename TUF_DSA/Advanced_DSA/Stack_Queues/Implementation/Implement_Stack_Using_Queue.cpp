#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue
{
  queue<int> q;

public:
  void push(int x)
  {
    int size = q.size();
    q.push(x);
    for (int i = 1; i <= size; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }

  int pop()
  {
    int popEle = q.front();
    q.pop();
    return popEle;
  }
  int top()
  {
    return q.front();
  }
};