#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int N, vector<vector<int>> arr)
{
  vector<int> adj[N];
  for (int i = 0; i < arr.size(); i++)
  {
    int u = arr[i][0];
    int v = arr[i][1];
    adj[v].push_back(u);
  }

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
  vector<int> ans;
  while (!q.empty())
  {
    int node = q.front();
    ans.push_back(node);
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
  if (ans.size() == N)
    return ans;
  return {};
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj.push_back({u, v});
  }
  vector<int> ans = findOrder(n, adj);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}