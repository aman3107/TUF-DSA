#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
  if (source == destination && grid[source.first][source.second] == 1)
  {
    return 0;
  }
  if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
    return -1;
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {source.first, source.second}});
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[source.first][source.second] = 0;
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  while (!q.empty())
  {
    int dis = q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int newRow = row + delRow[i];
      int newCol = col + delCol[i];
      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1)
      {
        if (dist[newRow][newCol] > dis + 1)
        {
          dist[newRow][newCol] = dis + 1;
          if (newRow == destination.first && newCol == destination.second)
          {
            return dist[newRow][newCol];
          }
          q.push({dist[newRow][newCol], {newRow, newCol}});
        }
      }
    }
  }
  return -1;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    grid.push_back(temp);
  }
  cout << shortestPath(grid, {0, 0}, {2, 2}) << endl;
}