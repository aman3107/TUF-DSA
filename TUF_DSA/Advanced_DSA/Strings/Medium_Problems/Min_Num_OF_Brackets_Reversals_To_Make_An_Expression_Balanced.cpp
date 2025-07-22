#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
  int n = s.size();
  if (n % 2 == 1)
    return -1;
  int open = 0;
  int close = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      open++;
    }
    else
    {
      if (open > 0)
      {
        open--;
      }
      else
      {
        close++;
      }
    }
  }
  return ((open / 2) + (open % 2) + (close / 2) + (close % 2));
}

int main()
{
  string s;
  cin >> s;
  cout << countRev(s) << endl;
}