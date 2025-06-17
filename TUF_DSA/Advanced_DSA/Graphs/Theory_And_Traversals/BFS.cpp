#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  queue<int> q;

  int vis[V] = {0};
  vis[0] = 1;

  q.push(0);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
      if (vis[adj[node][i]] != 1)
      {
        q.push(adj[node][i]);
        vis[adj[node][i]] = 1;
      }
    }
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> bfs = bfsOfGraph(n, adj);
  for (int i = 0; i < bfs.size(); i++)
  {
    cout << bfs[i] << " ";
  }
  cout << endl;
}