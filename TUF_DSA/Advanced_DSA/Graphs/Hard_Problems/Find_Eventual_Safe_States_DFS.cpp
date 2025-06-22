#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check)
{
  vis[node] = 1;
  pathVis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      if (dfs(it, adj, vis, pathVis, check))
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
  check[node] = 1;
  return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> pathVis(V, 0);
  vector<int> check(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      dfs(i, adj, vis, pathVis, check);
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (check[i] == 1)
    {
      ans.push_back(i);
    }
  }
  return ans;
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
  }
  vector<int> ans = eventualSafeNodes(n, adj);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}