#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
  if (dividend == divisor)
  {
    return 1;
  }
  bool isPositive = true;
  if (dividend >= 0 && divisor < 0)
  {
    isPositive = false;
  }
  else if (dividend < 0 && divisor > 0)
  {
    isPositive = false;
  }
  long long n = dividend;
  long long d = divisor;
  n = abs(n);
  d = abs(d);
  int ans = 0;
  while (n >= d)
  {
    int cnt = 0;
    while (n >= d << (cnt + 1))
    {
      cnt++;
    }
    ans += (1 << cnt);
    n = n - (d << cnt);
  }
  if (ans == (1 << 31) && isPositive)
    return INT_MAX;
  if (ans == (1 << 31) && !isPositive)
    return INT_MIN;
  return isPositive ? ans : -ans;
}

int divide2NumBrute(int dividend, int divisor)
{
  if (dividend == divisor)
  {
    return 1;
  }
  if (dividend == INT_MIN && divisor == -1)
  {
    return INT_MAX;
  }
  if (divisor == 1)
  {
    return dividend;
  }

  bool isPositive = true;
  if (divisor < 0 && dividend >= 0)
  {
    isPositive = false;
  }
  else if (dividend < 0 && divisor > 0)
  {
    isPositive = false;
  }

  long long n = dividend;
  long long d = divisor;
  long long sum = 0;
  int cnt = 0;
  n = abs(n);
  d = abs(d);
  while (sum + d <= n)
  {
    sum = sum + d;
    cnt++;
  }
  return isPositive ? cnt : -cnt;
}

int main()
{
  int divident;
  int divisor;
  cin >> divident >> divisor;
  cout << divide(divident, divisor) << endl;
}