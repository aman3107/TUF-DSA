#include <bits/stdc++.h>
using namespace std;

int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
  vector<pair<int, int>> adj[n];
  for (int i = 0; i < flights.size(); i++)
  {
    int u = flights[i][0];
    int v = flights[i][1];
    int p = flights[i][2];
    adj[u].push_back({v, p});
  }

  queue<pair<int, pair<int, int>>> q;
  // Stops,node,dist
  vector<int> dist(n, 1e9);
  q.push({0, {src, 0}});
  dist[src] = 0;
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int step = it.first;
    int node = it.second.first;
    int dis = it.second.second;
    if (step > K)
    {
      continue;
    }
    for (auto neighbor : adj[node])
    {
      int adjNode = neighbor.first;
      int price = neighbor.second;
      if (dist[adjNode] > price + dis)
      {
        dist[adjNode] = price + dis;
        q.push({step + 1, {adjNode, dist[adjNode]}});
      }
    }
  }
  if (dist[dst] == 1e9)
  {
    return -1;
  }
  return dist[dst];
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> flights;
  for (int i = 0; i < n; i++)
  {
    int u, v, p;
    cin >> u >> v >> p;
    flights.push_back({u, v, p});
  }
  cout << "Enter src dst and k" << endl;
  int src, dst, k;
  cin >> src >> dst >> k;
  cout << CheapestFlight(n, flights, src, dst, k) << endl;
}