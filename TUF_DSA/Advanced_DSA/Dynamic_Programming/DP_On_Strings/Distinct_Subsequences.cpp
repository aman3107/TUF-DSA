#include <bits/stdc++.h>
using namespace std;

/*
 Problem Statement
Given two strings s and t, return the number of distinct subsequences of s which equal t.
A subsequence is a string formed by deleting zero or more characters from s, without changing the order of the remaining characters.

🔍 Intuition
We build the solution using Dynamic Programming.
Let dp[i][j] represent the number of ways the first i characters of s can form the first j characters of t.
We reduce the space to two 1D arrays: prev (for i-1 row) and curr (for current i).

🧠 Core Idea
At every character position:
If s[i - 1] == t[j - 1], we have two choices:
Match both characters → dp[i-1][j-1]
Skip the character in s → dp[i-1][j]
So:
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
If s[i - 1] != t[j - 1], we can only skip the current character in s:
dp[i][j] = dp[i-1][j]
We use mod = 1e9 + 7 to prevent overflow.

⚙️ Approach (Tabulation with Space Optimization)
Create two 1D arrays prev and curr of size m + 1, initialized with 0.
Set prev[0] = curr[0] = 1, because an empty t is a subsequence of any prefix of s in 1 way.
Loop through i = 1 to n (characters of s)
Loop through j = 1 to m (characters of t)
If characters match:
curr[j] = (prev[j - 1] + prev[j]) % mod
Else:
curr[j] = prev[j]
After processing row i, assign curr to prev for the next iteration.
Return prev[m] — the answer for the full strings s and t.

💡 Why Use Two Arrays (prev and curr)?
We only need results from the previous row, so we reduce space from O(n * m) to O(2 * m).
Further optimization: you can use a single array, updating it backward from m → 1.

⏱️ Time & Space Complexity
Time: O(n * m)

Space: O(m) (due to two arrays of length m+1)



*/

int distinctSubsequencesTabu(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int mod = 1e9 + 7;
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);
  prev[0] = curr[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        curr[j] = (prev[j - 1] + prev[j]) % mod;
      }
      else
      {
        curr[j] = prev[j];
      }
    }
    prev = curr;
  }
  return prev[m];
}

int distinctSubsequencesTabu(string s, string t)
{
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][m];
}

int helperMemo(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
  if (j == 0)
    return 1;
  if (i == 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];
  if (s[i - 1] == t[j - 1])
  {
    return dp[i][j] = (helperMemo(i - 1, j - 1, s, t, dp) + helperMemo(i - 1, j, s, t, dp));
  }
  else
  {
    return dp[i][j] = helperMemo(i - 1, j, s, t, dp);
  }
}

int distinctSubsequencesMemo(string s, string t)
{
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return helperMemo(n, m, s, t, dp);
}

int helperRecur(int i, int j, string &s, string &t)
{
  if (j == 0)
    return 1;
  if (i == 0)
    return 0;

  if (s[i - 1] == t[j - 1])
  {
    return (helperRecur(i - 1, j - 1, s, t) + helperRecur(i - 1, j, s, t));
  }
  else
  {
    return helperRecur(i - 1, j, s, t);
  }
}

int distinctSubsequences(string s, string t)
{
  int n = s.size();
  int m = t.size();
  return helperRecur(n, m, s, t);
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << distinctSubsequencesMemo(s, t) << endl;
  cout << distinctSubsequences(s, t) << endl;
}