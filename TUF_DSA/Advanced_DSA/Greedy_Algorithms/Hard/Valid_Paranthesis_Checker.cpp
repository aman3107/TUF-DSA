#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  int n = s.size();
  int min = 0;
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      min++;
      max++;
    }
    else if (s[i] == ')')
    {
      min--;
      max--;
    }
    else
    {
      min--;
      max++;
    }

    if (min < 0)
      min = 0;
    if (max < 0)
      return false;
  }
  return (min == 0);
}

bool isValidBruteHelper(string s, int cnt, int i)
{
  if (cnt < 0)
  {
    return false;
  }
  if (i == s.size())
  {
    return (cnt == 0);
  }

  if (s[i] == '(')
  {
    return isValidBruteHelper(s, cnt + 1, i + 1);
  }
  if (s[i] == ')')
  {
    return isValidBruteHelper(s, cnt - 1, i + 1);
  }

  return isValidBruteHelper(s, cnt + 1, i + 1) || isValidBruteHelper(s, cnt - 1, i + 1) || isValidBruteHelper(s, cnt, i + 1);
}

bool isValidBrute(string s)
{
  // your code goes here
  return isValidBruteHelper(s, 0, 0);
}

int main()
{
  string s;
  cin >> s;
  cout << isValid(s) << endl;
}