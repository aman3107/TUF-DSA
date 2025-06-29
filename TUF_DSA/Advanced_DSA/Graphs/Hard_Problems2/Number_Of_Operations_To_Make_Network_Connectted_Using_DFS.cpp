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

int solve(int n, vector<vector<int>> &Edge)
{
  vector<int> adj[n];
  for (int i = 0; i < Edge.size(); i++)
  {
    int u = Edge[i][0];
    int v = Edge[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n, 0);
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      count++;
      dfs(i, adj, vis);
    }
  }
  if (Edge.size() >= count - 1)
  {
    return count - 1;
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