#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int V, int E, int S)
{
  // Write your code here.
  vector<pair<int, int>> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, S});
  vector<int> dist(V, INT_MAX);
  dist[S] = 0;
  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node])
    {
      int wt = it.second;
      int neighbour = it.first;
      if (dist[neighbour] > wt + dis)
      {
        dist[neighbour] = wt + dis;
        pq.push({dist[neighbour], neighbour});
      }
    }
  }
  return dist;
}
