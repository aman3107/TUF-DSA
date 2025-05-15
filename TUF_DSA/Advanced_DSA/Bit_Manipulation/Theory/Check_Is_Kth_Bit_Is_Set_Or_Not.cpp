#include <bits/stdc++.h>
using namespace std;

bool checkKthBitSetOrNotLeft(int n, int k)
{

  k = 1 << (k - 1);
  return (n & k) != 0;
}

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