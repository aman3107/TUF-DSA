#include <bits/stdc++.h>
using namespace std;

int minOperationsSpace(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
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
  return n + m - (2 * prev[m]);
}

int minOperationsTabu(string str1, string str2)
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
  return n + m - (2 * dp[n][m]);
}

int helperMemo(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
  if (i == 0 || j == 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (str1[i - 1] == str2[j - 1])
  {
    return dp[i][j] = 1 + helperMemo(i - 1, j - 1, str1, str2, dp);
  }
  return dp[i][j] = max(helperMemo(i - 1, j, str1, str2, dp), helperMemo(i, j - 1, str1, str2, dp));
}

int minOperationsMemo(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return n + m - (2 * helperMemo(n, m, str1, str2, dp));
}

int helperRecur(int i, int j, string &str1, string &str2)
{
  if (i == 0 || j == 0)
    return 0;

  if (str1[i - 1] == str2[j - 1])
  {
    return 1 + helperRecur(i - 1, j - 1, str1, str2);
  }
  return max(helperRecur(i - 1, j, str1, str2), helperRecur(i, j - 1, str1, str2));
}

int minOperations(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  return n + m - (2 * helperRecur(n, m, str1, str2));
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  cout << minOperations(s1, s2) << endl;
}