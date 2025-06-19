#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, int &time)
{
  queue<pair<int, pair<int, int>>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 2)
      {
        vis[i][j] = 2;
        q.push({0, {i, j}});
      }
    }
  }
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int freq = it.first;
    int row = it.second.first;
    int col = it.second.second;
    time = max(time, freq);
    for (int i = 0; i < 4; i++)
    {
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
      {
        vis[nRow][nCol] = 2;
        q.push({freq + 1, {nRow, nCol}});
      }
    }
  }
}

int orangesRotting(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int time = 0;
  bfs(vis, grid, n, m, time);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1 && vis[i][j] != 2)
      {
        return -1;
      }
    }
  }
  return time;
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
  cout << orangesRotting(adj) << endl;
}