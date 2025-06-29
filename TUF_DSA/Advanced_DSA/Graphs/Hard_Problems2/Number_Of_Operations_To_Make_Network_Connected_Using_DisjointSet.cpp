#include "DisjointSet.h"

int solve(int n, vector<vector<int>> &Edge)
{
  DisjointSet ds(n);
  int extraEdges = 0;
  for (auto it : Edge)
  {
    if (ds.find(it[0], it[1]))
    {
      extraEdges++;
    }
    else
    {
      ds.unionBySize(it[0], it[1]);
    }
  }
  int components = 0;
  for (int i = 0; i < n; i++)
  {
    if (ds.findUPar(i) == i)
    {
      components++;
    }
  }
  int count = components - 1;
  if (extraEdges >= count)
  {
    return count;
  }
  else
  {
    return -1;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edge;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    edge.push_back({u, v});
  }
  cout << solve(n, edge) << endl;
}