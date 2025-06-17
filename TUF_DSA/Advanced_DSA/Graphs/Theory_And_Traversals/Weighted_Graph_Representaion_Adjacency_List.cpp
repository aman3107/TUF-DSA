#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    cout << "Enter edges " << endl;
    int u, v;
    cin >> u >> v;
    cout << "Enter weight :" << endl;
    int wt;
    cin >> wt;

    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
}