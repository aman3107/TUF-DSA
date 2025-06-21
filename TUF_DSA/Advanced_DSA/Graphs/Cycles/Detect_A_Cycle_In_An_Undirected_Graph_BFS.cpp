#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<int> adj[], vector<int> &vis)
{
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int node = it.first;
    int parent = it.second;
    for (auto adjNodes : adj[node])
    {
      if (!vis[adjNodes])
      {
        vis[adjNodes] = 1;
        q.push({adjNodes, node});
      }
      else if (parent != adjNodes)
      {
        return true;
      }
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (bfs(i, adj, vis))
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
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << isCycle(n, adj) << endl;
}