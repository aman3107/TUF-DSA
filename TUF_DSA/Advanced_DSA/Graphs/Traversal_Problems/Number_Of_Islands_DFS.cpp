#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, int n, int m)
{
  if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0)
  {
    return;
  }
  grid[row][col] = 0;
  dfs(row - 1, col, grid, n, m);
  dfs(row + 1, col, grid, n, m);
  dfs(row, col - 1, grid, n, m);
  dfs(row, col + 1, grid, n, m);
}

void dfs1(int row, int col, vector<vector<int>> &grid, int n, int m)
{
  if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0)
  {
    return;
  }
  grid[row][col] = 0;
  for (int delRow = -1; delRow <= 1; delRow++)
  {
    for (int delCol = -1; delCol <= 1; delCol++)
    {
      int newRow = row + delRow;
      int newCol = col + delCol;
      dfs1(newRow, newCol, grid, n, m);
    }
  }
}

int numIslands(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  int count = 0;
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      if (grid[row][col] == 1)
      {
        count++;
        dfs1(row, col, grid, n, m);
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
