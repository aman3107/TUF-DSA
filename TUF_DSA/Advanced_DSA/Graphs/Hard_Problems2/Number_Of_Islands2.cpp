#include "DisjointSet.h"

vector<int> numOfIslands(int n, int m, vector<vector<int>> &A)
{
  DisjointSet ds(n * m);
  int k = A.size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int cnt = 0;
  vector<int> ans;
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  for (auto it : A)
  {
    int row = it[0];
    int col = it[1];
    if (vis[row][col] == 1)
    {
      ans.push_back(cnt);
      continue;
    }
    vis[row][col] = 1;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
      int nRow = (row + delRow[i]);
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
      {
        if (vis[nRow][nCol] == 1)
        {
          int nodeNo = (row * m) + col;
          int newNodeNo = (nRow * m) + nCol;
          if (ds.findUPar(nodeNo) != ds.findUPar(newNodeNo))
          {
            cnt--;
            ds.unionBySize(nodeNo, newNodeNo);
          }
        }
      }
    }
    ans.push_back(cnt);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << "Enter value of  k " << endl;
  int k;
  cin >> k;
  vector<vector<int>> edge;
  for (int i = 0; i < k; i++)
  {
    int u, v;
    cin >> u >> v;
    edge.push_back({u, v});
  }
  vector<int> ans = numOfIslands(n, m, edge);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}