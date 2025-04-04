#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
  long long int res = 1;
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}

int pascalTriangleI(int r, int c)
{
  return nCr(r - 1, c - 1);
}

int main()
{
  int r, c;
  cin >> r >> c;
  cout << pascalTriangleI(r, c) << endl;
  return 0;
}