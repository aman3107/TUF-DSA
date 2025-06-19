#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
{
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
      {
        if (grid[i][j] == 1)
        {
          vis[i][j] = 1;
          q.push({i, j});
        }
      }
    }
  }
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int row = it.first;
    int col = it.second;
    for (int i = 0; i < 4; i++)
    {
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
      {
        q.push({nRow, nCol});
        vis[nRow][nCol] = 1;
      }
    }
  }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  bfs(vis, grid, n, m);
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1 && !vis[i][j])
      {
        count++;
      }
    }
  }
  return count;
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
  cout << numberOfEnclaves(adj) << endl;
}