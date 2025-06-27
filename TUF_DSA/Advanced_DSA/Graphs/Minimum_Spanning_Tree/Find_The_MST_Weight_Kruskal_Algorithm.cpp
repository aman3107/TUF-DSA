#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> rank;
  vector<int> parent;
  vector<int> size;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }

  bool find(int u, int v)
  {
    return (findUPar(u) == findUPar(v));
  }

  void unionByRank(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] = size[ulp_v] + size[ulp_u];
    }
    else if (size[ulp_v] < size[ulp_u])
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] = size[ulp_u] + size[ulp_v];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] = size[ulp_u] + size[ulp_v];
    }
  }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
  DisjointSet ds(V);
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      edges.push_back({it[1], {i, it[0]}});
    }
  }
  sort(edges.begin(), edges.end());
  int mstWt = 0;
  for (auto it : edges)
  {
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;
    if (ds.findUPar(u) != ds.findUPar(v))
    {
      ds.unionBySize(u, v);
      mstWt = mstWt + wt;
    }
  }
  return mstWt;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> edges[n];
  for (int i = 0; i < n; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  cout << spanningTree(n, edges) << endl;
  // vector<pair<int, pair<int, int>>> ans = spanningTree2(n, edges);
  // for (auto &edge : ans)
  // {
  //   int u = edge.first;
  //   int v = edge.second.first;
  //   int wt = edge.second.second;

  //   cout << u << " " << v << " " << wt << endl;
  // }
}