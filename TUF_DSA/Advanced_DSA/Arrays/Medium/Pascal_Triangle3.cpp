#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangleIII(int n)
{
  vector<vector<int>> ans;
  for (int i = 1; i <= n; i++)
  {
    vector<int> temp(i, 0);
    temp[0] = 1;
    int res = 1;
    for (int j = 1; j < i; j++)
    {
      res = res * (i - j);
      res = res / j;
      temp[j] = res;
    }
    ans.push_back(temp);
  }
  return ans;
}

int main()
{
  int r;
  cin >> r;
  vector<vector<int>> ans = pascalTriangleIII(r);
  for (auto a : ans)
  {
    for (auto val : a)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}