#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n)
{
  int bits = 0;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      bits++;
    }
    n = n / 2;
  }
  return bits;
}