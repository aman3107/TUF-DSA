#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
  vector<vector<int>> adj(n, vector<int>(n, 1e9));
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u][v] = wt;
    adj[v][u] = wt;
  }
  for (int i = 0; i < n; i++)
  {
    adj[i][i] = 0;
  }
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  int maxCount = INT_MAX;
  int city = -1;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (adj[i][j] <= distanceThreshold)
      {
        cnt++;
      }
    }
    if (cnt <= maxCount)
    {
      maxCount = cnt;
      city = i;
    }
  }
  return city;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  cout << "Enter distance  threshold " << endl;
  int S;
  cin >> S;
  cout << findCity(n, m, edges, S) << endl;
}