#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  set<pair<int, int>> st;
  vector<int> dist(V, 1e9);
  st.insert({0, S});
  dist[S] = 0;
  while (!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;
    st.erase(it);
    for (auto neighbor : adj[node])
    {
      int adjNode = neighbor[0];
      int edgeWeight = neighbor[1];
      if (dist[adjNode] > dis + edgeWeight)
      {
        if (dist[adjNode] != 1e9)
        {
          st.erase({dist[adjNode], adjNode});
        }
        dist[adjNode] = dis + edgeWeight;
        st.insert({dist[adjNode], adjNode});
      }
    }
  }
  return dist;
}

int main()
{
  int n, s;
  cin >> n >> s;
  vector<vector<int>> adj[n] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
  vector<int> ans = dijkstra(n, adj, s);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}