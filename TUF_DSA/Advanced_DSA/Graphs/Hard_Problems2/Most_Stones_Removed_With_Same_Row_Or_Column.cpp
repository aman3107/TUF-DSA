#include "DisjointSet.h"

int maxRemove(vector<vector<int>> &stones, int n)
{
  int maxRow = 0;
  int maxCol = 0;
  for (auto it : stones)
  {
    maxRow = max(maxRow, it[0]);
    maxCol = max(maxCol, it[1]);
  }
  DisjointSet ds(maxRow + maxCol + 1);
  unordered_map<int, int> stonesNode;
  for (auto it : stones)
  {
    int nodeRow = it[0];
    int nodeCol = it[1] + maxRow + 1;
    ds.unionBySize(nodeRow, nodeCol);
    stonesNode[nodeRow] = 1;
    stonesNode[nodeCol] = 1;
  }
  int cnt = 0;
  for (auto it : stonesNode)
  {
    if (ds.findUPar(it.first) == it.first)
    {
      cnt++;
    }
  }
  return n - cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid;
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    grid.push_back({u, v});
  }
  cout << maxRemove(grid, n) << endl;
}