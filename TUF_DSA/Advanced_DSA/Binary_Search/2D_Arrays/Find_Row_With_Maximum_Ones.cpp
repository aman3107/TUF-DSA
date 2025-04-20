#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &mat)
{
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat;
  for (int i = 0; i < n; i++)
  {
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
      int val;
      cin >> val;
      v.push_back(val);
    }
    mat.push_back(v);
  }
}