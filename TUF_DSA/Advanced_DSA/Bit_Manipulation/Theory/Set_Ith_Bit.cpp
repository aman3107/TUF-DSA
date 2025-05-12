#include <bits/stdc++.h>
using namespace std;

int setIthBit(int n, int k)
{
  k = 1 << k;
  return (n | k);
}

int main()
{
  int n;
  int k;
  cin >> n >> k;
  cout << setIthBit(n, k) << endl;
}