#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int n, int m, int row0, int col0)
{
  if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col] == 1 || grid[row][col] == 0)
  {
    return;
  }
  vis[row][col] = 1;
  temp.push_back({row - row0, col - col0});
  dfs(row - 1, col, vis, grid, temp, n, m, row0, col0);
  dfs(row + 1, col, vis, grid, temp, n, m, row0, col0);
  dfs(row, col - 1, vis, grid, temp, n, m, row0, col0);
  dfs(row, col + 1, vis, grid, temp, n, m, row0, col0);
}

int countDistinctIslands(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  set<vector<pair<int, int>>> st;
  vector<pair<int, int>> temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1 && !vis[i][j])
      {
        temp.clear();
        dfs(i, j, vis, grid, temp, n, m, i, j);
        st.insert(temp);
      }
    }
  }
  return st.size();
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    adj.push_back(temp);
  }
  cout << countDistinctIslands(adj) << endl;
}