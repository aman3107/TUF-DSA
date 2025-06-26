#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>> &heights)
{
  int n = heights.size();
  int m = heights[0].size();
  //{diff,{row,col}}
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  pq.push({0, {0, 0}});
  dist[0][0] = 0;
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  while (!pq.empty())
  {
    int diff = pq.top().first;
    int row = pq.top().second.first;
    int col = pq.top().second.second;
    pq.pop();
    if (row == n - 1 && col == m - 1)
    {
      return diff;
    }
    for (int i = 0; i < 4; i++)
    {
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
      {
        int absDiff = abs(heights[row][col] - heights[nRow][nCol]);
        int newEffort = max(absDiff, diff);
        if (newEffort < dist[nRow][nCol])
        {
          pq.push({newEffort, {nRow, nCol}});
          dist[nRow][nCol] = newEffort;
        }
      }
    }
  }
  return 0; // Just for not getting runtime error
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
  cout << MinimumEffort(grid) << endl;
}