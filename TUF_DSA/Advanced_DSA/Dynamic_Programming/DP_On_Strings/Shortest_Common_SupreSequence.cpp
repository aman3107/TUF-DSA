#include <bits/stdc++.h>
using namespace std;

/*
✅ 1. Intuition
🔍 What is the Shortest Common Supersequence?
The Shortest Common Supersequence (SCS) of two strings str1 and str2 is the shortest string that:
Contains both str1 and str2 as subsequences
Maintains the order of characters in both strings
💡 Think of it as a smart merge of str1 and str2 that avoids repeating the common parts.
💡 Core Insight
To build the SCS, we:

Keep the common characters (LCS) only once
Merge the rest of the characters from both strings in order
✅ 2. Approach

🧠 What’s happening?
dp[i][j] stores the length of the LCS between str1[0..i-1] and str2[0..j-1].
If characters match, we extend the LCS.
If not, we choose the longer LCS by skipping one character.
We backtrack from dp[n][m] to dp[0][0].
If characters match → add once and move diagonally.
If they don’t → move in direction of greater LCS and add that unmatched character.
One string may finish early.
We add remaining characters to complete the SCS.
Since we built the string from the end, we reverse it at the end.
*/

string shortestCommonSupersequence(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string ans = "";
  int i = n;
  int j = m;

  while (i > 0 && j > 0)
  {
    if (str1[i - 1] == str2[j - 1])
    {
      ans += str1[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      ans += str1[i - 1];
      i--;
    }
    else
    {
      ans += str2[j - 1];
      j--;
    }
  }

  while (i > 0)
  {
    ans += str1[i - 1];
    i--;
  }
  while (j > 0)
  {
    ans += str2[j - 1];
    j--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << shortestCommonSupersequence(s1, s2) << endl;
}