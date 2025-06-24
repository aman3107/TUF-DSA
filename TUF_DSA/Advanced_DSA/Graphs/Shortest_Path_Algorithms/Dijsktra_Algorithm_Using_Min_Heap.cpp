#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, S});
  vector<int> dist(V, 1e9);
  dist[S] = 0;
  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node])
    {
      int wt = it[1];
      int neighbour = it[0];
      if (dist[neighbour] > wt + dis)
      {
        dist[neighbour] = wt + dis;
        pq.push({dist[neighbour], neighbour});
      }
    }
  }
  return dist;
}

int main()
{
  int n, s;
  cin >> n >> s;
  vector<vector<int>> adj[n] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
  vector<int> ans = dijkstra(n, adj, s);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}