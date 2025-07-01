#include <bits/stdc++.h>
using namespace std;

int fibTabu(int n)
{
  vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int fibMemo(int n, vector<int> &memo)
{
  if (n <= 1)
  {
    return n;
  }
  if (memo[n] != -1)
  {
    return memo[n];
  }
  memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
  return memo[n];
}

int fibonacci(int n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n;
  cin >> n;
  vector<int> memo(n + 1, -1);
  cout << fibMemo(n, memo) << endl;
  cout << fibTabu(n) << endl;
  cout << fibonacci(n) << endl;
}