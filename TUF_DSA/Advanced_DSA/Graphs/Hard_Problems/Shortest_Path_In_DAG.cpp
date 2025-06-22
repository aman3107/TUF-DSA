#include <bits/stdc++.h>
using namespace std;

void dfsTopoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it.first])
    {
      dfsTopoSort(it.first, adj, vis, st);
    }
  }
  st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
  vector<pair<int, int>> adj[N];
  for (int i = 0; i < M; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    adj[u].push_back({v, w});
  }
  stack<int> st;
  vector<int> vis(N, 0);
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
    {
      dfsTopoSort(i, adj, vis, st);
    }
  }
  vector<int> dist(N, 1e9);
  dist[0] = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    if (dist[node] != 1e9)
    {
      for (auto it : adj[node])
      {
        int v = it.first;
        int wt = it.second;
        if (dist[node] + wt < dist[v])
        {
          dist[v] = dist[node] + wt;
        }
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (dist[i] == 1e9)
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
    int u, v, w;
    cin >> u >> v >> w;
    adj.push_back({u, v, w});
  }
  vector<int> ans = shortestPath(n, m, adj);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}