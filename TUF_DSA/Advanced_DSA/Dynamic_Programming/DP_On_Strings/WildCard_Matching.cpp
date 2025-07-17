#include <bits/stdc++.h>
using namespace std;

/*
✅ Intuition
We are given a string str and a pattern pat. The pattern can include:
'?' which matches exactly one character.
'*' which matches zero or more characters.
We want to check if the pattern pat matches the entire string str.
This is a classic Dynamic Programming (DP) problem where:
We consider subproblems like: Does the first i characters of pat match the first j characters of str?
We solve it by building up solutions for smaller substrings.
We use a space-optimized DP where we only keep track of the previous and current rows (prev and curr) to reduce memory usage.

🛠️ Approach
Step 1: Define the DP State
Let dp[i][j] represent whether the first i characters of pat match the first j characters of str.
In this code, we reduce it to two 1D arrays:
prev[j] → result for pattern up to i-1
curr[j] → result for pattern up to i

Step 2: Base Case Initialization
prev[0] = 1: Empty pattern matches empty string.
prev[j] = 0 for j > 0: Empty pattern cannot match any non-empty string.

Step 3: Loop Over Pattern Characters (i)
For each character pat[i-1]:
We first check if the pattern up to i is all '*', because only such patterns can match an empty string.
If yes, then curr[0] = 1, else curr[0] = 0.

Step 4: Loop Over String Characters (j)
For each str[j-1], check the pattern character pat[i-1]:
If pat[i-1] == str[j-1] or pat[i-1] == '?'
→ we take the diagonal result: curr[j] = prev[j - 1]
If pat[i-1] == '*'
→ Two possibilities:
Treat '*' as empty: prev[j]
Treat '*' as matching one or more characters: curr[j - 1]
→ So: curr[j] = prev[j] || curr[j - 1]
Else (mismatch) → curr[j] = 0

Step 5: Transition
At the end of each i loop:
prev = curr;
We move the curr row up to become the new prev.

Step 6: Final Answer
Return:
prev[m]
Which tells whether pat[0..n-1] matches str[0..m-1].

Time: O(n × m)
Where n = pat.size(), m = str.size()

Space: O(m)
Using only two 1D arrays of size m+1
*/

bool wildCardSpace(string str, string pat)
{
  int n = pat.size();
  int m = str.size();
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);

  prev[0] = 1;
  for (int j = 1; j <= m; j++)
  {
    prev[j] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    int allStars = 1;
    for (int k = 1; k <= i; k++)
    {
      if (pat[k - 1] != '*')
      {
        allStars = 0;
        break;
      }
    }
    curr[0] = allStars;
    for (int j = 1; j <= m; j++)
    {
      if (pat[i - 1] == str[j - 1] || pat[i - 1] == '?')
        curr[j] = prev[j - 1];
      else if (pat[i - 1] == '*')
      {
        curr[j] = prev[j] || curr[j - 1];
      }
      else
      {
        curr[j] = 0;
      }
    }
    prev = curr;
  }
  return prev[m];
}

bool wildCardTabu(string str, string pat)
{
  int n = pat.size();
  int m = str.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 1;
  for (int j = 1; j <= m; j++)
  {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    int allStars = 1;
    for (int k = 1; k <= i; k++)
    {
      if (pat[k - 1] != '*')
      {
        allStars = 0;
        break;
      }
    }
    dp[i][0] = allStars;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (pat[i - 1] == str[j - 1] || pat[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (pat[i - 1] == '*')
      {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  return dp[n][m];
}

bool helperMemo(int i, int j, string &pat, string &str, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return true;
  if (i == 0 && j > 0)
    return false;
  if (j == 0 && i > 0)
  {
    for (int k = 1; k <= i; k++)
    {
      if (pat[k - 1] != '*')
        return false;
    }
    return true;
  }

  if (dp[i][j] != -1)
    return dp[i][j];

  if (pat[i - 1] == str[j - 1] || pat[i - 1] == '?')
    return dp[i][j] = helperMemo(i - 1, j - 1, pat, str, dp);
  else if (pat[i - 1] == '*')
  {
    return dp[i][j] = helperMemo(i - 1, j, pat, str, dp) || helperMemo(i, j - 1, pat, str, dp);
  }
  return dp[i][j] = false;
}

bool wildCardMemo(string str, string pat)
{
  int n = pat.size();
  int m = str.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return helperMemo(n, m, pat, str, dp);
}

bool helperRecur(int i, int j, string &pat, string &str)
{
  if (i == 0 && j == 0)
    return true;
  if (i == 0 && j > 0)
    return false;
  if (j == 0 && i > 0)
  {
    for (int k = 1; k <= i; k++)
    {
      if (pat[k - 1] != '*')
        return false;
    }
    return true;
  }

  if (pat[i - 1] == str[j - 1] || pat[i - 1] == '?')
    return helperRecur(i - 1, j - 1, pat, str);
  else if (pat[i - 1] == '*')
  {
    return helperRecur(i - 1, j, pat, str) || helperRecur(i, j - 1, pat, str);
  }
  return false;
}

bool wildCard(string str, string pat)
{
  int n = pat.size();
  int m = str.size();
  return helperRecur(n, m, pat, str);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << wildCardMemo(s1, s2) << endl;
  cout << wildCard(s1, s2) << endl;
}