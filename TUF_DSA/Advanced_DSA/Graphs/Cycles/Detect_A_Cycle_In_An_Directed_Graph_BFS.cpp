#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int N, vector<int> adj[])
{
  vector<int> indegree(N, 0);
  for (int i = 0; i < N; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < N; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  int cnt = 0;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cnt++;
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
  }
  if (cnt == N)
    return false;
  return true;
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
    adj[v].push_back(u);
  }
  cout << isCyclic(n, adj) << endl;
}