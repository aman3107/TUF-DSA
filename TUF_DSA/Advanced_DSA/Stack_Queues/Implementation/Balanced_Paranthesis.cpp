#include <bits/stdc++.h>
using namespace std;

bool isMatched(char open, char close)
{
  if ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
  {
    return true;
  }
  return false;
}

bool isValid(string str)
{
  stack<int> s;
  int n = str.size();
  for (int i = 0; i < n; i++)
  {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[')
    {
      s.push(str[i]);
    }
    else
    {
      if (s.empty())
      {
        return false;
      }
      int ch = s.top();
      s.pop();

      if (!isMatched(ch, str[i]))
      {
        return false;
      }
    }
  }
  return s.empty();
}

int main()
{
  string s;
  cin >> s;

  cout << isValid(s) << endl;
}