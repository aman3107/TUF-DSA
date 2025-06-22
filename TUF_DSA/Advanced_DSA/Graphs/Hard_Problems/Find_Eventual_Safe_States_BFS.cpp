#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
  }
  return indegree;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
  vector<int> adjRev[V];
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      adjRev[it].push_back(i);
    }
  }
  vector<int> indegree = topoSort(V, adjRev);
  vector<int> ans;
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int> ans = eventualSafeNodes(n, adj);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}