#include <bits/stdc++.h>
using namespace std;

bool checkKthBitSetOrNot(int n, int k)
{

  n = n >> (k - 1);
  return (n & 1) != 0;
}

int main()
{
  int n;
  int k;
  cin >> n >> k;
  cout << checkKthBitSetOrNot(n, k) << endl;
}