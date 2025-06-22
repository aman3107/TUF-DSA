#include <bits/stdc++.h>
using namespace std;

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

bool canFinish(int N, vector<vector<int>> arr)
{
  vector<int> adj[N];
  for (int i = 0; i < arr.size(); i++)
  {
    int u = arr[i][0];
    int v = arr[i][1];
    adj[v].push_back(u);
  }
  vector<int> vis(N, 0);
  vector<int> pathVis(N, 0);
  for (int i = 0; i < N; i++)
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
  cout << canFinish(n, adj) << endl;
}