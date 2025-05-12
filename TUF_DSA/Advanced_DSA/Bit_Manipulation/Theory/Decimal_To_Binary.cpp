#include <bits/stdc++.h>
using namespace std;

string binaryPuzzle(int n)
{
  // Write your code here.
  string ans = "";
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      ans = ans + '1';
    }
    else
    {
      ans = ans + '0';
    }
    n = n / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int decimalToBinary(int n)
{
  int ans = 0;
  int pv = 1;
  while (n > 0)
  {
    int rem = n % 2;
    ans = ans + rem * pv;
    n = n / 2;
    pv = pv * 10;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  int ans = decimalToBinary(n);
  cout << ans << endl;
  return 0;
}