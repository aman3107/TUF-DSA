#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> adj[], vector<int> &dist)
{
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    if (dist[node] != INT_MAX)
    {
      for (auto it : adj[node])
      {
        if (dist[it] > dist[node] + 1)
        {
          dist[it] = dist[node] + 1;
          q.push(it);
        }
      }
    }
  }
}

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
{
  vector<int> adj[N];
  for (int i = 0; i < M; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dist(N, INT_MAX);
  bfs(0, adj, dist);
  for (int i = 0; i < N; i++)
  {
    if (dist[i] == INT_MAX)
    {
      dist[i] = -1;
    }
  }
  return dist;
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
  vector<int> bfs = shortestPath(adj, n, m);
  for (int i = 0; i < bfs.size(); i++)
  {
    cout << bfs[i] << " ";
  }
  cout << endl;
}