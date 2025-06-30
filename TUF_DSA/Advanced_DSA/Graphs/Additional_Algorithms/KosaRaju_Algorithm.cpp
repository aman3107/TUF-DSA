#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto adjNode : adj[node])
  {
    if (!vis[adjNode])
      dfs(adjNode, adj, vis, st);
  }
  st.push(node);
}

void dfs1(int node, vector<int> transposeAdj[], vector<int> &vis)
{
  vis[node] = 1;
  for (auto adjNode : transposeAdj[node])
  {
    if (!vis[adjNode])
      dfs1(adjNode, transposeAdj, vis);
  }
}

int kosaraju(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  // Store all the finishing time in the stack
  stack<int> st;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      dfs(i, adj, vis, st);
    }
  }
  // Reverse all the edges
  vector<int> transposeAdj[V];
  for (int i = 0; i < V; i++)
  {
    vis[i] = 0;
    for (auto it : adj[i])
    {
      // i->it
      // it->i
      transposeAdj[it].push_back(i);
    }
  }
  int cnt = 0;

  // traverse all the nodes to find strongely connected components
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    if (!vis[node])
    {
      cnt++;
      dfs1(node, transposeAdj, vis);
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<int> adj[n];
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  cout << kosaraju(n, adj) << endl;
}