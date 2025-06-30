#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &timeInsertion, vector<int> &lowTimeInsertion, vector<vector<int>> &bridges)
{
  vis[node] = 1;
  timeInsertion[node] = timer;
  lowTimeInsertion[node] = timer;
  timer++;

  for (auto adjNode : adj[node])
  {
    if (adjNode == parent)
      continue;
    else if (vis[adjNode] == 0)
    {
      dfs(adjNode, node, adj, vis, timeInsertion, lowTimeInsertion, bridges);
      lowTimeInsertion[node] = min(lowTimeInsertion[node], lowTimeInsertion[adjNode]);
      if (lowTimeInsertion[adjNode] > timeInsertion[node])
      {
        bridges.push_back({node, adjNode});
      }
    }
    else
    {
      lowTimeInsertion[node] = min(lowTimeInsertion[node], lowTimeInsertion[adjNode]);
    }
  }
}

vector<vector<int>> criticalConnections(int V, vector<vector<int>> &E)
{
  vector<int> adj[V];
  for (auto it : E)
  {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> bridges;
  vector<int> vis(V, 0);
  vector<int> timeInsertion(V, 0);
  vector<int> lowTimeInsertion(V, 0);

  dfs(0, -1, adj, vis, timeInsertion, lowTimeInsertion, bridges);
  return bridges;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edges;
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  vector<vector<int>> ans = criticalConnections(V, edges);
  for (auto it : ans)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
}