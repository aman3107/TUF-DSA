#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis);
    }
  }
}

int findNumberOfComponent(int V, vector<vector<int>> &edges)
{
  int E = edges.size();
  vector<int> adj[V];
  for (int i = 0; i < E; i++)
  {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }
  vector<int> vis(V, 0);
  int count = 0;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      count++;
      dfs(i, adj, vis);
    }
  }
  return count;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj.push_back({u, v});
  }

  cout << findNumberOfComponent(n, adj) << endl;
}