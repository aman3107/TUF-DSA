#include <bits/stdc++.h>
using namespace std;

/*
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The goal is to find the minimum number of operations required to convert one string (start) into another (target).
Allowed operations:

Insert a character
Delete a character
Replace a character

This is a classic dynamic programming problem. Instead of solving it recursively (which is slow), we build the solution from the bottom up using tabulation. To save space, we only keep two 1D arrays instead of a full 2D DP table.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Define the Problem as a DP Table
Let dp[i][j] be the minimum number of operations to convert the first i characters of start to the first j characters of target.

However, you only need the current row and the previous row at any time — so you use:

prev[j]: stores the result for row i-1
curr[j]: stores the result for row i

2. Base Case Initialization
for (int j = 0; j <= m; j++)
    prev[j] = j;
This handles converting an empty start to target[0..j-1], which takes j insertions.

Each row also starts with:
curr[0] = i;
This handles converting start[0..i-1] to an empty target, which takes i deletions.

3. Filling the DP Table
For each character pair (i, j):

Insert: Add target[j-1] to start → solve for dp[i][j-1]
Delete: Remove start[i-1] → solve for dp[i-1][j]
Replace: Replace start[i-1] with target[j-1] → solve for dp[i-1][j-1]
Take the minimum of the three, and add 1 for the operation.

4. Update Rows
After filling curr, copy it into prev for the next iteration.
After processing all characters of start, the result is the value to convert all of start to target.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
Time Complexity: O(n * m) – two nested loops over string lengths

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
Space Complexity: O(m) – using only two 1D arrays instead of full DP table
*/

int editDistanceTabu(string start, string target)
{
  int n = start.size();
  int m = target.size();
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);

  for (int j = 0; j <= m; j++)
  {
    prev[j] = j;
  }
  for (int i = 1; i <= n; i++)
  {
    curr[0] = i;
    for (int j = 1; j <= m; j++)
    {
      if (start[i - 1] == target[j - 1])
      {
        curr[j] = prev[j - 1];
      }
      else
      {
        int ins_operation = 1 + curr[j - 1];
        int del_operation = 1 + prev[j];
        int repl_operation = 1 + prev[j - 1];
        curr[j] = min(ins_operation, min(del_operation, repl_operation));
      }
    }
    prev = curr;
  }
  return prev[m];
}

int editDistanceTabu(string start, string target)
{
  int n = start.size();
  int m = target.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int j = 0; j <= m; j++)
  {
    dp[0][j] = j;
  }
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (start[i - 1] == target[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        int ins_operation = 1 + dp[i][j - 1];
        int del_operation = 1 + dp[i - 1][j];
        int repl_operation = 1 + dp[i - 1][j - 1];
        dp[i][j] = min(ins_operation, min(del_operation, repl_operation));
      }
    }
  }
  return dp[n][m];
}

int helperMemo(int i, int j, string &start, string &target, vector<vector<int>> &dp)
{
  if (i == 0)
    return dp[i][j] = j;
  if (j == 0)
    return dp[i][j] = i;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (start[i - 1] == target[j - 1])
    return helperMemo(i - 1, j - 1, start, target, dp);

  int ins_operation = 1 + helperMemo(i, j - 1, start, target, dp);
  int del_operation = 1 + helperMemo(i - 1, j, start, target, dp);
  int repl_operation = 1 + helperMemo(i - 1, j - 1, start, target, dp);
  return dp[i][j] = min(ins_operation, min(del_operation, repl_operation));
}

int editDistanceMemo(string start, string target)
{
  int n = start.size();
  int m = target.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return helperMemo(n, m, start, target, dp);
}

int helperRecur(int i, int j, string &start, string &target)
{
  if (i == 0)
    return j;
  if (j == 0)
    return i;

  if (start[i - 1] == target[j - 1])
    return helperRecur(i - 1, j - 1, start, target);

  int ins_operation = 1 + helperRecur(i, j - 1, start, target);
  int del_operation = 1 + helperRecur(i - 1, j, start, target);
  int repl_operation = 1 + helperRecur(i - 1, j - 1, start, target);
  return min(ins_operation, min(del_operation, repl_operation));
}

int editDistance(string start, string target)
{
  int n = start.size();
  int m = target.size();
  return helperRecur(n, m, start, target);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << editDistanceTabu(s1, s2) << endl;
  cout << editDistanceMemo(s1, s2) << endl;
  cout << editDistance(s1, s2) << endl;
}