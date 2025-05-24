#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  int n = s.size();
  int minLen = INT_MAX;
  int sIndex = -1;
  int hash[256] = {0};
  for (auto c : t)
  {
    hash[c]++;
  }
  int r = 0;
  int l = 0;
  int cnt = 0;
  while (r < n)
  {
    if (hash[s[r]] > 0)
    {
      cnt++;
    }
    hash[s[r]]--;
    while (cnt == t.size())
    {
      hash[s[l]]++;
      if (minLen > (r - l + 1))
      {
        minLen = (r - l + 1);
        sIndex = l;
      }
      if (hash[s[l]] > 0)
      {
        cnt--;
      }
      l++;
    }
    r++;
  }
  return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}

string minWindowBrute(string s, string t)
{
  // your code goes here
  int minLen = INT_MAX;
  int n = s.size();
  int sIndex = -1;
  for (int i = 0; i < n; i++)
  {
    int hash[256] = {0};
    for (auto c : t)
    {
      hash[c]++;
    }
    int cnt = 0;
    for (int j = i; j < n; j++)
    {
      if (hash[s[j]] > 0)
      {
        cnt++;
      }

      hash[s[j]]--;

      if (cnt == t.size())
      {
        int len = j - i + 1;
        if (minLen > len)
        {
          minLen = len;
          sIndex = i;
        }
        break;
      }
    }
  }
  return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}

int main()
{
  string s;
  cin >> s;
  string t;
  cin >> t;
  cout << minWindow(s, t) << endl;
}