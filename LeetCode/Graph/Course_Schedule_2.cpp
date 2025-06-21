#include <bits/stdc++.h>
using namespace std;

class Solution
{
  bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, stack<int> &st)
  {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (dfs(it, adj, vis, pathVis, st))
        {
          return true;
        }
      }
      else if (pathVis[it])
      {
        return true;
      }
    }
    pathVis[node] = 0;
    st.push(node);
    return false;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> adj[numCourses];

    for (int i = 0; i < prerequisites.size(); i++)
    {
      int u = prerequisites[i][0];
      int v = prerequisites[i][1];
      adj[v].push_back(u);
    }
    vector<int> vis(numCourses, 0);
    vector<int> pathVis(numCourses, 0);
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < numCourses; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, adj, vis, pathVis, st))
        {
          return {};
        }
      }
    }
    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }
    return ans;
  }
};