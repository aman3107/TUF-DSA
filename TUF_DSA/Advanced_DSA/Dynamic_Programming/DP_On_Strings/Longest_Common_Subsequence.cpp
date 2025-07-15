#include <bits/stdc++.h>
using namespace std;

/*
✅ Function: helperMemo
Parameters: Two indices (ind1, ind2) into s1 and s2.

Base case: If either index is below 0, return 0.

Memoization: Stored in dp[ind1][ind2].

Logic:

If characters match: 1 + recurse both indices.

Else: take the maximum by skipping one character in either string.
✅ Function: lcsMemo
Initializes a dp table of size str1.size() × str2.size().

Calls the helper function on the full strings.
*/

int lcsSpace(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);
  for (int ind1 = 1; ind1 <= n; ind1++)
  {
    for (int ind2 = 1; ind2 <= m; ind2++)
    {
      if (str1[ind1 - 1] == str2[ind2 - 1])
        curr[ind2] = 1 + prev[ind2 - 1];
      else
      {
        curr[ind2] = max(prev[ind2], curr[ind2 - 1]);
      }
    }
    prev = curr;
  }
  return prev[m];
}

int lcsTabu(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int ind1 = 1; ind1 <= n; ind1++)
  {
    for (int ind2 = 1; ind2 <= m; ind2++)
    {
      if (str1[ind1 - 1] == str2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
      {
        dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
      }
    }
  }
  return dp[n][m];
}

int helperMemo(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
  if (ind1 == 0 || ind2 == 0)
    return 0;
  if (dp[ind1][ind2] != -1)
  {
    return dp[ind1][ind2];
  }
  if (s1[ind1 - 1] == s2[ind2 - 1])
  {
    return dp[ind1][ind2] = 1 + helperMemo(ind1 - 1, ind2 - 1, s1, s2, dp);
  }
  return dp[ind1][ind2] = max(helperMemo(ind1 - 1, ind2, s1, s2, dp), helperMemo(ind1, ind2 - 1, s1, s2, dp));
}

int lcsMemo(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return helperMemo(n, m, str1, str2, dp);
}

int helperRecur(int ind1, int ind2, string &s1, string &s2)
{
  // Base Case
  if (ind1 == 0 || ind2 == 0)
    return 0;
  // If both the string character is matches
  if (s1[ind1 - 1] == s2[ind2 - 1])
    return 1 + helperRecur(ind1 - 1, ind2 - 1, s1, s2);
  // If not matches then we will check for both by skipping one character from both and take the maximum of both
  return max(helperRecur(ind1 - 1, ind2, s1, s2), helperRecur(ind1, ind2 - 1, s1, s2));
}

int lcs(string str1, string str2)
{
  int ind1 = str1.size();
  int ind2 = str2.size();
  return helperRecur(ind1, ind2, str1, str2);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << lcs(s1, s2) << endl;
}