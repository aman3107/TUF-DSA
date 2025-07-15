#include <bits/stdc++.h>
using namespace std;

/*
What is the problem?
You're given a string s. You need to find the length of the longest subsequence of s that is also a palindrome.
A subsequence is a sequence you can get by deleting zero or more characters (but not changing the order).
A palindrome is a sequence that reads the same forward and backward.

Approach Overview
To find the Longest Palindromic Subsequence (LPS), we:
Reverse the string s and call it s2.
Compute the Longest Common Subsequence (LCS) of the original string s1 and its reverse s2.
The LCS of a string and its reverse is the length of the LPS.

s1 = original string
s2 = reversed string
We’ll compute LCS between s1 and s2.
prev stores results from the previous row of the DP table.
curr stores results for the current row.
We loop over all characters of both strings. i and j start from 1 because the 0th row/column are initialized to 0 (base case of LCS).
If characters match, we add 1 to the value from the diagonal in the DP table (prev[j - 1]), meaning we extend the LCS.
If characters don't match, we take the max between:
prev[j]: value from previous string character
curr[j - 1]: value from previous reversed string character



To find the LPS of a string s, you reverse the string and compute the Longest Common Subsequence (LCS) between s and reverse(s).
This works because the LCS between a string and its reverse gives the LPS.
You’ve used a 1D DP optimization using two vectors: prev and curr.


*/

int minInsertionSpace(string s)
{
  int n = s.size();
  string s1 = s;
  reverse(s.begin(), s.end());
  string s2 = s;
  vector<int> prev(n + 1, 0);
  vector<int> curr(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
      }
      else
      {
        curr[j] = max(prev[j], curr[j - 1]);
      }
    }
    prev = curr;
  }
  return n - prev[n];
}

int minInsertionTabu(string s)
{
  int n = s.size();
  string s1 = s;
  reverse(s.begin(), s.end());
  string s2 = s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return n - dp[n][n];
}

int helperMemo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
  if (i == 0 || j == 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s1[i - 1] == s2[j - 1])
  {
    return dp[i][j] = 1 + helperMemo(i - 1, j - 1, s1, s2, dp);
  }
  return dp[i][j] = max(helperMemo(i - 1, j, s1, s2, dp), helperMemo(i, j - 1, s1, s2, dp));
}

int minInsertionMemo(string s)
{
  int n = s.size();
  string s1 = s;
  reverse(s.begin(), s.end());
  string s2 = s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return n - helperMemo(n, n, s1, s2, dp);
}

int helperRecur(int i, int j, string &s1, string &s2)
{
  if (i == 0 || j == 0)
    return 0;
  if (s1[i - 1] == s2[j - 1])
    return 1 + helperRecur(i - 1, j - 1, s1, s2);
  return max(helperRecur(i - 1, j, s1, s2), helperRecur(i, j - 1, s1, s2));
}

int minInsertion(string s)
{
  int n = s.size();
  string s1 = s;
  reverse(s.begin(), s.end());
  string s2 = s;
  return n - helperRecur(n, n, s1, s2);
}

int main()
{
  string s1;
  cin >> s1;
  cout << minInsertionSpace(s1) << endl;
  cout << minInsertionTabu(s1) << endl;
  cout << minInsertionMemo(s1) << endl;
  cout << minInsertion(s1) << endl;
}