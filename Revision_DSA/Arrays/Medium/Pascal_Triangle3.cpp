#include <bits/stdc++.h>
using namespace std;

/*
 Approach:
Loop over each row from 1 to n.

Initialize:

res = 1 for the first element of each row (which is always 1).

A temporary vector temp to hold the current row.

Loop over columns (from 1 to i - 1) to compute each value using the previous one:
res = res * (i - j);
res = res / j;
temp.push_back(res);
Add the row to the final answer.
*/

vector<vector<int>> pascalTriangleIII(int n)
{
  vector<vector<int>> ans;
  // check for each row 1 based indexing
  for (int i = 1; i <= n; i++)
  {
    // inserting the first element
    int res = 1;
    vector<int> temp;
    temp.push_back(res);
    // check for each column
    for (int j = 1; j < i; j++)
    {
      res = res * (i - j);
      res = res / j;
      temp.push_back(res);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> ans = pascalTriangleIII(n);
  for (auto &it : ans)
  {
    for (auto &it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
  cout << endl;
}