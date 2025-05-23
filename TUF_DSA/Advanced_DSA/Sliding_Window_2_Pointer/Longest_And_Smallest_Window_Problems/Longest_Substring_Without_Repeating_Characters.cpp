#include <bits/stdc++.h>
using namespace std;

int longestNonRepeatingSubstring(string &s)
{
  int n = s.size();
  int l = 0;
  int r = 0;
  int maxSum = 0;
  int len = 0;
  int hash[256];
  for (int i = 0; i < 256; i++)
  {
    hash[i] = -1;
  }
  while (r < n)
  {
    if (hash[s[r]] >= l)
    {
      l = hash[s[r]] + 1;
    }
    hash[s[r]] = r;
    len = r - l + 1;
    maxSum = max(maxSum, len);
    r++;
  }

  return maxSum;
}

int longestNonRepeatingSubstringBrute2(string &s)
{
  // your code goes here
  int n = s.size();
  int maxSum = 0;
  for (int i = 0; i < n; i++)
  {
    int hash[256] = {0};
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      if (hash[s[j]] == 1)
      {
        break;
      }
      hash[s[j]]++;
      sum++;
    }
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

int longestNonRepeatingSubstringBrute1(string &s)
{
  // your code goes here
  int n = s.size();
  int maxSum = 0;
  for (int i = 0; i < n; i++)
  {
    string sub = "";
    for (int j = i; j < n; j++)
    {
      if (sub.find(s[j]) != string::npos)
      {
        break;
      }
      sub = sub + s[j];
    }
    int len = sub.size();
    maxSum = max(maxSum, len);
  }
  return maxSum;
}

int main()
{
  string s;
  cin >> s;
  cout << longestNonRepeatingSubstring(s) << endl;
}