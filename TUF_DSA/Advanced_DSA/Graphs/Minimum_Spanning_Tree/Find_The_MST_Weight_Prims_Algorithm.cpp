#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int V, int m, vector<pair<pair<int, int>, int>> &g)
{
  // Write your code here.
  vector<pair<int, int>> adj[V];
  for (auto &edge : g)
  {
    int u = edge.first.first - 1;
    int v = edge.first.second - 1;
    int wt = edge.second;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  vector<int> vis(V, 0);
  vector<pair<pair<int, int>, int>> mst;
  pq.push({0, {0, -1}});

  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int wt = it.first;
    int node = it.second.first;
    int parent = it.second.second;
    if (vis[node])
      continue;
    vis[node] = 1;

    if (parent != -1)
    {
      // Convert back to 1-based for output
      mst.push_back({{parent + 1, node + 1}, wt});
    }

    for (auto &nbr : adj[node])
    {
      int adjNode = nbr.first;
      int edgeWt = nbr.second;
      if (!vis[adjNode])
        pq.push({edgeWt, {adjNode, node}});
    }
  }

  return mst;
}

vector<pair<int, pair<int, int>>> spanningTree2(int V, vector<vector<int>> adj[])
{
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  vector<int> vis(V, 0);
  vector<pair<int, pair<int, int>>> mst;
  pq.push({0, {0, -1}});
  // {edgeWright , {node, parent}}
  int sum = 0;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int wt = it.first;
    int node = it.second.first;
    int parent = it.second.second;
    if (vis[node])
      continue;
    vis[node] = 1;
    if (parent != -1)
    {
      mst.push_back({parent, {node, wt}});
      sum += wt;
    }
    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int edgeWt = it[1];
      if (!vis[adjNode])
      {
        pq.push({edgeWt, {adjNode, node}});
      }
    }
  }
  return mst;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(V, 0);
  pq.push({0, 0});
  int sum = 0;
  while (!pq.empty())
  {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (vis[node])
      continue;
    // Add it to the mst
    vis[node] = 1;
    sum += weight;
    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int edgeWeight = it[1];
      if (!vis[adjNode])
      {
        pq.push({edgeWeight, adjNode});
      }
    }
  }
  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> edges[n];
  for (int i = 0; i < n; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  cout << spanningTree(n, edges) << endl;
  vector<pair<int, pair<int, int>>> ans = spanningTree2(n, edges);
  for (auto &edge : ans)
  {
    int u = edge.first;
    int v = edge.second.first;
    int wt = edge.second.second;

    cout << u << " " << v << " " << wt << endl;
  }
}