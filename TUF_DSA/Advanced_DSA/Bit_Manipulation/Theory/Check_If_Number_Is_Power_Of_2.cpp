#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
  if (n == 0)
  {
    return false;
  }
  long long a = n;
  if ((a & (a - 1)) == 0)
  {
    return true;
  }
  return false;
}
int main()
{
  int n;
  cin >> n;
  cout << isPowerOfTwo(n) << endl;
}