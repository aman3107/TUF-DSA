#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m)
{
  if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 'X' || vis[row][col] == 1)
  {
    return;
  }
  vis[row][col] = 1;
  dfs(row - 1, col, vis, grid, n, m);
  dfs(row + 1, col, vis, grid, n, m);
  dfs(row, col - 1, vis, grid, n, m);
  dfs(row, col + 1, vis, grid, n, m);
}

vector<vector<char>> fill(vector<vector<char>> mat)
{
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
      {
        if (mat[i][j] == 'O' && !vis[i][j])
        {
          dfs(i, j, vis, mat, n, m);
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == 'O' && !vis[i][j])
      {
        mat[i][j] = 'X';
      }
    }
  }
  return mat;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> adj;
  for (int i = 0; i < n; i++)
  {
    vector<char> temp;
    for (int j = 0; j < m; j++)
    {
      char data;
      cin >> data;
      temp.push_back(data);
    }
    adj.push_back(temp);
  }
  vector<vector<char>> ans = fill(adj);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}