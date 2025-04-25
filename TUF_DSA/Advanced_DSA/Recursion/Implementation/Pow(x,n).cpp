#include <bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
  if (n == 0)
  {
    return 1;
  }
  if (n == 1)
  {
    return x;
  }

  if (n % 2 == 0)
  {
    return power(x * x, n / 2);
  }
  else
  {
    return x * power(x, n - 1);
  }
}

double myPowRecursive(double x, int n)
{
  if (n < 0)
  {
    return power(1 / x, -1 * n);
  }
  else
  {
    return power(x, n);
  }
}

double myPow(double x, int n)
{
  if (x == 1.0 || n == 0)
  {
    return 1;
  }
  long long temp = n;
  double ans = 1;
  if (n < 0)
  {
    x = 1 / x;
    temp = -1 * 1LL * n;
  }
  while (temp > 0)
  {
    if (temp % 2 == 1)
    {
      ans = ans * x;
      temp = temp - 1;
    }
    else
    {
      x *= x;
      temp /= 2;
    }
  }
  return ans;
}

double myPowBrute(double x, int n)
{
  // your code goes here
  if (x == 0 || n == 1)
  {
    return 1;
  }
  double ans = 1;
  if (n < 0)
  {
    x = 1 / x;
    n = -n;
  }

  for (int i = 1; i <= n; i++)
  {
    ans = ans * x;
  }
  return ans;
}

int main()
{
  double x;
  int n;
  cin >> x >> n;
  cout << myPowRecursive(x, n) << endl;
}