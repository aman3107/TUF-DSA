#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &timeInsertion, vector<int> &lowTimeInsertion, vector<int> &mark)
{
  vis[node] = 1;
  timeInsertion[node] = timer;
  lowTimeInsertion[node] = timer;
  timer++;
  int child = 0;
  for (auto it : adj[node])
  {
    if (it == parent)
      continue;
    else if (vis[it] == 0)
    {
      dfs(it, node, adj, vis, timeInsertion, lowTimeInsertion, mark);
      lowTimeInsertion[node] = min(lowTimeInsertion[node], lowTimeInsertion[it]);
      if (lowTimeInsertion[it] >= timeInsertion[node] && parent != -1)
      {
        mark[node] = 1;
      }
      child++;
    }
    else
    {
      lowTimeInsertion[node] = min(lowTimeInsertion[node], timeInsertion[it]);
    }
  }
  if (child > 1 && parent == -1)
  {
    mark[node] = 1;
  }
}

vector<int> articulationPoints(int n, vector<int> adj[])
{
  vector<int> vis(n, 0);
  vector<int> timeInsertion(n, 0);
  vector<int> lowTimeInsertion(n, 0);
  vector<int> mark(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
      dfs(i, -1, adj, vis, timeInsertion, lowTimeInsertion, mark);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (mark[i] == 1)
    {
      ans.push_back(i);
    }
  }
  if (ans.size() == 0)
    return {-1};
  return ans;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ans = articulationPoints(V, adj);
  for (auto it : ans)
  {
    cout << it << " " << endl;
  }
}