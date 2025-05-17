#include <bits/stdc++.h>
using namespace std;

int findXORHelper(int n)
{
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  if (n % 4 == 3)
    return 0;
  return n;
}

int findRangeXOR(int l, int r)
{
  return findXORHelper(l - 1) ^ findXORHelper(r);
}

int findRangeXORBrute(int l, int r)
{
  // your code goes here
  int ans = 0;
  for (int i = l; i <= r; i++)
  {
    ans = ans ^ i;
  }
  return ans;
}

int main()
{
  int l, r;
  cin >> l >> r;

  cout << findRangeXOR(l, r) << endl;
  return 0;
}