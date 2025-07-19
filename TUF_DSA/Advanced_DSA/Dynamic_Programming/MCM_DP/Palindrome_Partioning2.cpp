#include <bits/stdc++.h>
using namespace std;

bool palindrome(int l, int r, string &s)
{
  while (l < r)
  {
    if (s[l] != s[r])
    {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int minCutTabu(string s)
{
  // your code goes here
  int n = s.size();
  vector<int> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    int mini = INT_MAX;
    string temp = "";
    for (int j = i; j < n; j++)
    {
      temp += s[j];
      if (palindrome(i, j, s))
      {
        int cost = 1 + dp[j + 1];
        mini = min(mini, cost);
      }
    }
    dp[i] = mini;
  }
  return dp[0] - 1;
}

int helperMemo(int i, string &s, vector<int> &dp)
{
  if (i == s.size())
    return 0;
  if (dp[i] != -1)
    return dp[i];
  int mini = INT_MAX;
  string temp = "";
  for (int j = i; j < s.size(); j++)
  {
    temp += s[j];
    if (palindrome(i, j, s))
    {
      int cost = 1 + helperMemo(j + 1, s, dp);
      mini = min(mini, cost);
    }
  }
  return dp[i] = mini;
}

int minCutMemo(string s)
{
  // your code goes here
  int n = s.size();
  vector<int> dp(n + 1, -1);
  return helperMemo(0, s, dp) - 1;
}

int helperRecur(int i, string &s)
{
  if (i == s.size())
    return 0;
  int mini = INT_MAX;
  string temp = "";
  for (int j = i; j < s.size(); j++)
  {
    temp += s[j];
    if (palindrome(i, j, s))
    {
      int cost = 1 + helperRecur(j + 1, s);
      mini = min(mini, cost);
    }
  }
  return mini;
}

int minCut(string s)
{
  // your code goes here
  return helperRecur(0, s) - 1;
}

int main()
{
  string s;
  cin >> s;
  cout << minCutTabu(s) << endl;
  cout << minCutMemo(s) << endl;
  cout << minCut(s) << endl;
}