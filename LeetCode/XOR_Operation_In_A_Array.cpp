#include <bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start)
{

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int num = start + 2 * i;
    ans ^= num;
  }
  return ans;
}

int main()
{
  int start, n;
  cin >> n >> start;
  cout << xorOperation(n, start) << endl;
}