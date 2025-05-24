#include <bits/stdc++.h>
using namespace std;

int kDistinctChar(string &s, int k)
{
  int r = 0;
  int l = 0;
  int n = s.size();
  int maxLen = 0;
  unordered_map<int, int> ump;
  while (r < n)
  {
    ump[s[r]]++;
    if (ump.size() > k)
    {
      ump[s[l]]--;
      if (ump[s[l]] == 0)
      {
        ump.erase(s[l]);
      }
      l++;
    }
    if (ump.size() <= k)
    {
      int len = r - l + 1;
      maxLen = max(maxLen, len);
    }
    r++;
  }
  return maxLen;
}

int kDistinctCharBetter(string &s, int k)
{
  int l = 0;
  int r = 0;
  int n = s.size();
  int maxLen = 0;
  unordered_map<char, int> ump;
  while (r < n)
  {
    ump[s[r]]++;
    while (ump.size() > k)
    {
      ump[s[l]]--;
      if (ump[s[l]] == 0)
      {
        ump.erase(s[l]);
      }
      l++;
    }
    if (ump.size() <= k)
    {
      int len = r - l + 1;
      maxLen = max(maxLen, len);
    }
    r++;
  }
  return maxLen;
}

int kDistinctCharBrute(string &s, int k)
{
  // your code goes here
  int maxLen = 0;
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    unordered_set<char> st;
    for (int j = i; j < n; j++)
    {
      st.insert(s[j]);
      if (st.size() <= k)
      {
        int len = j - i + 1;
        maxLen = max(maxLen, len);
      }
      else
      {
        break;
      }
    }
  }
  return maxLen;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << kDistinctCharBetter(s, k) << endl;
}