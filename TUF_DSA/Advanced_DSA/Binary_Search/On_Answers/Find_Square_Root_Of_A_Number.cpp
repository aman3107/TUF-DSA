#include <bits/stdc++.h>
using namespace std;

long long floorSqrt(long long n)
{
  if (n == 0)
    return 0;
  long long low = 1;
  long long high = n;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    long long val = mid * mid;
    if (val <= n)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return high;
}

long long floorSqrtBrute(long long n)
{
  int i = 0;
  int ans = 1;
  while (ans <= n)
  {
    i++;
    ans = i * i;
  }
  return i - 1;
}

int main()
{
  long long n;
  cin >> n;
  cout << floorSqrt(n) << endl;
}