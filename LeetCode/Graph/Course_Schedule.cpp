#include <bits/stdc++.h>
using namespace std;

class Solution
{
  bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
  {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (dfs(it, adj, vis, pathVis))
        {
          return true;
        }
      }
      else if (pathVis[it])
      {
        return true;
      }
    }
    pathVis[node] = 0;
    return false;
  }

public:
  bool canFinish(int V, vector<vector<int>> &edges)
  {
    vector<int> adj[V];
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, adj, vis, pathVis))
        {
          return false;
        }
      }
    }
    return true;
  }
};