#include <bits/stdc++.h>
using namespace std;

void helper(int node, vector<int> adj[], vector<int> &dfs, int vis[])
{
  vis[node] = 1;
  dfs.push_back(node);
  for (auto it : adj[node])
  {
    if (vis[it] == 0)
    {
      helper(it, adj, dfs, vis);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> dfs;
  int vis[V] = {0};
  helper(0, adj, dfs, vis);
  return dfs;
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
  vector<int> bfs = dfsOfGraph(n, adj);
  for (int i = 0; i < bfs.size(); i++)
  {
    cout << bfs[i] << " ";
  }
  cout << endl;
}