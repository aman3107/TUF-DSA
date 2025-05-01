#include <bits/stdc++.h>
using namespace std;

bool isPossible(int num, int node, vector<vector<int>> &adj, vector<int> &colors)
{
  for (int i = 0; i < adj[node].size(); i++)
  {
    if (colors[adj[node][i]] == num)
    {
      return false;
    }
  }
  return true;
}

bool graphColoringHelper(int node, vector<int> &colors, vector<vector<int>> &adj, int m, int n)
{
  if (node == n)
  {
    return true;
  }
  for (int num = 1; num <= m; num++)
  {
    if (isPossible(num, node, adj, colors))
    {
      colors[node] = num;
      bool val = graphColoringHelper(node + 1, colors, adj, m, n);
      if (val == true)
      {
        return true;
      }
      colors[node] = 0;
    }
  }
  return false;
}

bool graphColoring(vector<vector<int>> &edges, int m, int n)
{
  // your code goes here

  // Create Adjacency List
  vector<vector<int>> adj(n);
  for (int i = 0; i < edges.size(); i++)
  {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }
  vector<int> colors(n, 0);
  return graphColoringHelper(0, colors, adj, m, n);
}

int main()
{
  int n, m;
  cin >> n >> m;
  int e;
  cin >> e;
  vector<vector<int>> edges;
  for (int i = 0; i < e; i++)
  {
    vector<int> temp;
    for (int j = 0; j < 2; j++)
    {
      int val;
      cin >> val;
      temp.push_back(val);
    }
    edges.push_back(temp);
  }
  cout << graphColoring(edges, m, n) << endl;
}