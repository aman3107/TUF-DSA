#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangle2(int r)
{
  int res = 1;
  vector<int> ans;
  ans.push_back(1);
  for (int i = 1; i < r; i++)
  {
    res = res * (r - i);
    res = res / i;
    ans.push_back(res);
  }
  return ans;
}

int main()
{
  int r;
  cin >> r;
  vector<int> ans = pascalTriangle2(r);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}