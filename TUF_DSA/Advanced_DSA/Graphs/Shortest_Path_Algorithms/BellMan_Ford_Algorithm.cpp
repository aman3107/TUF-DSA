#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
  vector<int> dist(V, 1e9);
  dist[S] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (dist[u] != 1e9 && dist[v] > dist[u] + wt)
      {
        dist[v] = dist[u] + wt;
      }
    }
  }

  // Nth relaxation to check negative cycle
  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    if (dist[u] != 1e9 && dist[v] > dist[u] + wt)
    {
      return {-1};
    }
  }
  return dist;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> roads;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    roads.push_back({u, v, w});
  }
  cout << "Enter source vertex " << endl;
  int S;
  cin >> S;
  vector<int> ans = bellman_ford(n, roads, S);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}