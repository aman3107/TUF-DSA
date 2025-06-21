#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &color, int col)
{
  color[node] = col;
  for (auto neighbor : adj[node])
  {
    if (color[neighbor] == -1)
    {
      if (!dfs(neighbor, adj, color, 1 - color[node]))
      {
        return false;
      }
    }
    else if (color[neighbor] == color[node])
    {
      return false;
    }
  }
  return true;
}

bool bfs(int src, vector<int> adj[], vector<int> &color)
{
  color[src] = 0;
  queue<int> q;
  q.push(src);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto it : adj[node])
    {
      if (color[it] == -1)
      {
        color[it] = 1 - color[node];
        q.push(it);
      }
      else if (color[it] == color[node])
      {
        return false;
      }
    }
  }
  return true;
}

bool isBipartite(int V, vector<int> adj[])
{
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
    {
      if (!dfs(i, adj, color, 0))
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
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << isBipartite(n, adj) << endl;
}