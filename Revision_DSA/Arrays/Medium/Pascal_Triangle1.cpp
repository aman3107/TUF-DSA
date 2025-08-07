#include <bits/stdc++.h>
using namespace std;

/*
Identify the given row and column position in Pascal's Triangle.
Compute the binomial coefficient nCr using the formula nCr = n! / (r! * (n-r)!).
Optimize the calculation by selecting the smaller value between r and (n-r) to minimize iterations.
Initialize the result as 1. Iterate through the range, updating the result using multiplication and division to prevent overflow.
Return the computed nCr, which represents the value at the specified position in Pascal's Triangle.
*/

int pascalTriangleI(int r, int c)
{
  int res = 1;
  r = r - 1;
  c = c - 1;
  for (int i = 0; i < c; i++)
  {
    res = res * (r - i);
    res = res / (i + 1);
  }
  return res;
}

int main()
{
  int r, c;
  cin >> r >> c;
  cout << pascalTriangleI(r, c) << endl;
}