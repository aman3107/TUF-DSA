#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
  // Mark node visited and path of node visited
  vis[node] = 1;
  pathVis[node] = 1;

  // Traverse for adjacent Nodes
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      if (dfs(it, adj, vis, pathVis))
      {
        return true;
      }
    }
    // if node is visited and it's path is also visited
    else if (pathVis[it])
    {
      return true;
    }
  }
  pathVis[node] = 0;
  return false;
}

bool isCyclic(int N, vector<int> adj[])
{
  vector<int> vis(N, 0);
  vector<int> pathVis(N, 0);
  // Check for all components
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
    {
      if (dfs(i, adj, vis, pathVis))
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << isCyclic(n, adj) << endl;
}