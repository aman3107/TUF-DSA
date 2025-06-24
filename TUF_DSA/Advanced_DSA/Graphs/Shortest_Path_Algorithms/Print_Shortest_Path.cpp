#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n + 1, 1e9);
  vector<int> memo(n + 1, 0);
  for (int i = 0; i <= n; i++)
  {
    memo[i] = i;
  }
  pq.push({0, 1});
  dist[1] = 0;
  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node])
    {
      int adjNode = it.first;
      int edgeWeight = it.second;
      if (dist[adjNode] > dis + edgeWeight)
      {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dist[adjNode], adjNode});
        memo[adjNode] = node;
      }
    }
  }
  if (dist[n] == 1e9)
    return {-1};
  vector<int> path;
  int node = n;
  while (memo[node] != node)
  {
    path.push_back(node);
    node = memo[node];
  }
  path.push_back(1);
  reverse(path.begin(), path.end());
  path.insert(path.begin(), dist[n]);
  return path;
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
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}