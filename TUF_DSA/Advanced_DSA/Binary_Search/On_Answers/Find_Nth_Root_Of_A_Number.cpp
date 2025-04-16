#include <bits/stdc++.h>
using namespace std;

int exponentiationBySquaringModify(int mid, int exp, int M)
{
  long long result = 1, base = mid;
  while (exp > 0)
  {
    if (exp % 2 == 1)
    {
      result = result * base;
      exp--;
      if (result > M)
        return 2;
    }
    else
    {
      base = base * base;
      exp /= 2;
      if (base > M)
        return 2;
    }
  }
  if (result == M)
    return 1;
  return 0;
}

long long exponentiationBySquaring(int base, int exp)
{
  long long result = 1, base = base;
  while (exp > 0)
  {
    if (exp % 2 == 1)
    {
      result = result * base;
      exp--;
    }
    else
    {
      base = base * base;
      exp /= 2;
    }
  }
  return result;
}

int NthRoot(int N, int M)
{
  int low = 1;
  int high = M;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int val = exponentiationBySquaringModify(mid, N, M);
    if (val == 1)
    {
      return mid;
    }
    else if (val == 0)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int NthRootBrute(int N, int M)
{
  for (int i = 1; i <= M; i++)
  {
    long long val = exponentiationBySquaring(i, N);
    if (val == (long long)M)
    {
      return i;
    }
    else if (val > (long long)M)
    {
      break;
    }
  }
  return -1;
}

int main()
{
  int n, m;
  cin >> n >> m;

  cout << NthRoot(n, m) << endl;
}