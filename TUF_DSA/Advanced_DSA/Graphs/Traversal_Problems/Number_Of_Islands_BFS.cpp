#include <bits/stdc++.h>
using namespace std;

void bfs4(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
{
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});

  // Only 4 directions: up, down, left, right
  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};

  while (!q.empty())
  {
    int curRow = q.front().first;
    int curCol = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newRow = curRow + dRow[i];
      int newCol = curCol + dCol[i];

      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
          grid[newRow][newCol] == 1 && !vis[newRow][newCol])
      {
        vis[newRow][newCol] = 1;
        q.push({newRow, newCol});
      }
    }
  }
}

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
{
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int row = it.first;
    int col = it.second;
    for (int delRow = -1; delRow <= 1; delRow++)
    {
      for (int delCol = -1; delCol <= 1; delCol++)
      {
        int newRow = row + delRow;
        int newCol = col + delCol;
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol])
        {
          vis[newRow][newCol] = 1;
          q.push({newRow, newCol});
        }
      }
    }
  }
}

int numIslands(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int count = 0;
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      if (!vis[row][col] && grid[row][col] == 1)
      {
        count++;
        bfs(row, col, vis, grid, n, m);
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
  cout << numIslands(adj) << endl;
}