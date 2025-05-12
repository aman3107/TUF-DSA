#include <bits/stdc++.h>
using namespace std;

int convert(int N, string &str)
{
  // Write your code here.
  int ans = 0;
  int exp = 1;
  for (int i = N - 1; i >= 0; i--)
  {
    if (str[i] == '1')
    {
      ans = ans + exp * 1;
    }
    exp = exp * 2;
  }
  return ans;
}

int binaryToDecimal(int n)
{
  int exp = 1;
  int ans = 0;

  while (n > 0)
  {
    int rem = n % 10;
    ans = ans + exp * rem;
    n = n / 10;
    exp = exp * 2;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << ~(5) << endl;
  int ans = binaryToDecimal(n);
  cout << ans << endl;
  return 0;
}