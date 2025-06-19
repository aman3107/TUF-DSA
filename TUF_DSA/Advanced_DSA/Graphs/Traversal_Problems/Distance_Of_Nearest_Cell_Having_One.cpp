#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &vis, vector<vector<int>> &grid, vector<vector<int>> &ans, int n, int m)
{
  queue<pair<int, pair<int, int>>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1)
      {
        vis[i][j] = 1;
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
    ans[row][col] = freq;
    for (int i = 0; i < 4; i++)
    {
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 0 && !vis[nRow][nCol])
      {
        vis[nRow][nCol] = 1;
        q.push({freq + 1, {nRow, nCol}});
      }
    }
  }
}

vector<vector<int>> nearest(vector<vector<int>> grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<int>> ans(n, vector<int>(m, 0));
  bfs(vis, grid, ans, n, m);
  return ans;
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
  vector<vector<int>> ans = nearest(adj);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}