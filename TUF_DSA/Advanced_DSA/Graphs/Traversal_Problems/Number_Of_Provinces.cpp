#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis);
    }
  }
}

int numProvinces(vector<vector<int>> adj)
{
  int n = adj.size();
  vector<int> adjLs[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (adj[i][j] == 1 && i != j)
      {
        adjLs[i].push_back(j);
        adjLs[j].push_back(i);
      }
    }
  }
  vector<int> vis(n + 1, 0);
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      count++;
      dfs(i, adjLs, vis);
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> adj;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    adj.push_back(temp);
  }
  cout << numProvinces(adj) << endl;
  return 0;
}