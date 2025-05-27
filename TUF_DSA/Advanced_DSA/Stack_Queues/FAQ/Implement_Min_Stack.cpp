#include <bits/stdc++.h>
using namespace std;

class MinStack
{
  stack<int> st;
  int mini;

public:
  MinStack()
  {
    mini = INT_MAX;
  }
  void push(int x)
  {
    if (st.empty())
    {
      st.push(x);
      mini = x;
    }
    else
    {

      if (mini < x)
      {
        st.push(x);
      }
      else
      {
        int newVal = 2 * x - mini;
        mini = x;
        st.push(newVal);
      }
    }
  }
  void pop()
  {
    if (st.empty())
    {
      return;
    }
    int val = st.top();
    st.pop();
    if (val < mini)
    {
      mini = 2 * mini - val;
    }
  }

  int getMin()
  {
    if (st.empty())
    {
      return -1;
    }
    return mini;
  }
  int top()
  {
    if (st.empty())
    {
      return -1;
    }
    int val = st.top();
    if (val < mini)
    {
      return mini;
    }
    else
    {
      return val;
    }
  }
};

class MinStackBrute
{
  stack<pair<int, int>> st;

public:
  void push(int x)
  {
    if (st.empty())
    {
      st.push({x, x});
    }
    else
    {
      int mini = st.top().second;
      if (mini < x)
      {
        st.push({x, mini});
      }
      else
      {
        st.push({x, x});
      }
    }
  }
  void pop()
  {
    st.pop();
  }
  int top()
  {
    return st.top().first;
  }
  int getMin()
  {
    return st.top().second;
  }
};

int main()
{
}