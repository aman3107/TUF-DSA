#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
  vector<pair<int, int>> adj[n];
  for (int i = 0; i < roads.size(); i++)
  {
    int u = roads[i][0];
    int v = roads[i][1];
    int w = roads[i][2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<long long> dist(n, LLONG_MAX);
  vector<long long> ways(n, 0);
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
  pq.push({0, 0});
  dist[0] = 0;
  ways[0] = 1;
  int mod = (1e9 + 7);
  while (!pq.empty())
  {
    long long dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node])
    {
      int adjNode = it.first;
      long long edgeWeight = it.second;
      if (dist[adjNode] > (dis + edgeWeight))
      {
        dist[adjNode] = (dis + edgeWeight);
        ways[adjNode] = ways[node];
        pq.push({dist[adjNode], adjNode});
      }
      else if (dist[adjNode] == dis + edgeWeight)
      {
        ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
      }
    }
  }
  return (ways[n - 1]);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> roads;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    roads.push_back({u, v, w});
  }
  cout << countPaths(n, roads) << endl;
}