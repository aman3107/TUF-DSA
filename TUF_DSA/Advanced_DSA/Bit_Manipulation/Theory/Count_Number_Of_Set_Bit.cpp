#include <bits/stdc++.h>
using namespace std;

int countSetBits1ToN(int n)
{
  // Write your code here
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    count += __builtin_popcount(i);
  }
  return count % 1000000007;
}

int decToBin3(int n)
{
  int count = 0;
  while (n > 0)
  {
    count++;
    n = n & (n - 1); // Every Time number AND with 1 minus number
  }
  return count;
}

int decToBin2(int n)
{
  int count = 0;
  while (n > 0)
  {
    cout << n << endl;
    if (n & 1) // Always Checks odd number
    {
      count++;
    }
    n = n >> 1; // Always divided by 2
  }
  return count;
}

int decToBin(int n)
{
  int count = 0;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      count++;
    }
    n = n / 2;
  }
  return count;
}

int countSetBit(int n)
{
  return decToBin2(n);
}

int main()
{
  int n;
  cin >> n;
  cout << countSetBit(n) << endl;
}