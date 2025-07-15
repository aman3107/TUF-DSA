#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstrSpace(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  int ans = 0;
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
        ans = max(ans, curr[j]);
      }
      else
      {
        curr[j] = 0;
      }
    }
    prev = curr;
  }
  return ans;
}

int longestCommonSubstrTabu(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  return ans;
}

/*
Memoization (dp[i][j]) is used to store the results of overlapping subproblems.

The recursive call helperMemo(i, j, ...) is run inside nested loops to cover all (i, j) combinations, because:

The longest common substring can end at any position.

The count variable tracks the maximum length found so far.

dp[i][j] = 0 is correctly used when characters don’t match — this breaks the substring chain.


*/

int helperMemo(int i, int j, string &s1, string &s2, int &count, vector<vector<int>> &dp)
{
  if (i == 0 || j == 0)
    return 0;
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  if (s1[i - 1] == s2[j - 1])
  {
    dp[i][j] = 1 + helperMemo(i - 1, j - 1, s1, s2, count, dp);
    count = max(count, dp[i][j]);
    return dp[i][j];
  }
  return dp[i][j] = 0;
}

int longestCommonSubstrMemo(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      helperMemo(i, j, str1, str2, count, dp);
    }
  }
  return count;
}

int helperRecur(int i, int j, string &s1, string &s2, int count)
{
  if (i == 0 || j == 0)
    return count;
  int newCount = count;
  if (s1[i - 1] == s2[j - 1])
  {
    newCount = helperRecur(i - 1, j - 1, s1, s2, count + 1);
  }
  int op1 = helperRecur(i - 1, j, s1, s2, 0);
  int op2 = helperRecur(i, j - 1, s1, s2, 0);
  return max(newCount, max(op1, op2));
}

int longestCommonSubstr(string str1, string str2)
{
  int count = helperRecur(str1.size(), str2.size(), str1, str2, 0);
  return count;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << longestCommonSubstrSpace(s1, s2) << endl;
  cout << longestCommonSubstr(s1, s2) << endl;
}