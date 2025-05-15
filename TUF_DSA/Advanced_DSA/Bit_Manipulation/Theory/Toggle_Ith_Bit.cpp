#include <bits/stdc++.h>
using namespace std;

int toggleBitsH(int n, int k)
{
  k = 1 << (k);
  return n ^ k;
}
int toggleKBits(int n, int k)
{
  // Write your code here
  for (int i = 0; i < k; i++)
  {
    n = toggleBitsH(n, i);
  }
  return n;
}

int toggleIthBit(int n, int k)
{
  k = 1 << k;
  return n ^ k;
}

int main()
{
  int n;
  int k;
  cin >> n >> k;
  cout << toggleIthBit(n, k) << endl;
}