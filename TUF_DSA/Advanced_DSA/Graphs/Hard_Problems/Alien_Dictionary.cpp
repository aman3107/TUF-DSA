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
  return ans;
}

string findOrder(string dict[], int N, int k)
{
  vector<int> adj[k];
  for (int i = 0; i < N - 1; i++)
  {
    string str1 = dict[i];
    string str2 = dict[i + 1];
    int l1 = 0;
    int l2 = 0;
    while (l1 < str1.size() && l2 < str2.size())
    {
      if (str1[l1] != str2[l2])
      {
        adj[str1[l1] - 'a'].push_back(str2[l2] - 'a');
        break;
      }
      l1++;
      l2++;
    }
  }

  vector<int> topo = topoSort(k, adj);
  string ans = "";
  for (auto it : topo)
  {
    ans += char(it + 'a');
  }
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  string str[n];
  for (int i = 0; i < n; i++)
  {
    string data;
    cin >> data;
    str[i] = data;
  }
  cout << findOrder(str, n, k) << endl;
}