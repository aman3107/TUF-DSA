#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &vis, int row, int col, int n)
{
  int r = row, c = col;
  while (r >= 0)
  {
    if (vis[r][c] == 1)
    {
      return false;
    }
    r--;
  }
  r = row;
  c = col;
  while (r >= 0 && c >= 0)
  {
    if (vis[r][c] == 1)
    {
      return false;
    }
    r--;
    c--;
  }
  r = row;
  c = col;
  while (r >= 0 && c < n)
  {
    if (vis[r][c] == 1)
    {
      return false;
    }
    r--;
    c++;
  }
  return true;
}

void solveNQueensHelper(int row, vector<vector<int>> &ans, vector<vector<int>> &vis, int n)
{
  if (row == n)
  {
    vector<int> temp;
    for (auto arr : vis)
    {
      for (int el : arr)
      {
        temp.push_back(el);
      }
    }
    ans.push_back(temp);
    return;
  }

  for (int col = 0; col < n; col++)
  {
    if (safe(vis, row, col, n))
    {
      vis[row][col] = 1;
      solveNQueensHelper(row + 1, ans, vis, n);
      vis[row][col] = 0;
    }
  }
  return;
}

vector<vector<int>> solveNQueens(int n)
{
  // Write your code here.
  vector<vector<int>> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  solveNQueensHelper(0, ans, vis, n);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> ans = solveNQueens(n);
  for (auto a : ans)
  {
    for (auto el : a)
    {
      cout << el << " ";
    }
    cout << endl;
  }
}