#include <bits/stdc++.h>
using namespace std;

void generateSet(int ind, int n, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans)
{
  if (ind == n)
  {
    ans.push_back(arr);
    return;
  }
  // take
  arr.push_back(nums[ind]);
  generateSet(ind + 1, n, arr, nums, ans);
  // not take
  arr.pop_back();
  generateSet(ind + 1, n, arr, nums, ans);
}

vector<vector<int>> powerSet(vector<int> &nums)
{
  // your code goes here
  vector<int> arr;
  vector<vector<int>> ans;
  generateSet(0, nums.size(), arr, nums, ans);
  return ans;
}

void generate(int i, string s, int o, int c, vector<string> &ans, int n)
{
  if (i == 2 * n)
  {
    if (o == c)
    {
      ans.push_back(s);
    }
    return;
  }
  if (o < n)
    generate(i + 1, s + "(", o + 1, c, ans, n);
  if (c < o)
    generate(i + 1, s + ")", o, c + 1, ans, n);
}

vector<string> generateParenthesis(int n)
{
  // your code goes here
  vector<string> ans;
  generate(0, "", 0, 0, ans, n);
  return ans;
}

double power(double x, long long n)
{
  if (n == 0)
    return 1.0;
  if (n == 1)
    return x;
  if (n % 2 == 0)
  {
    return power(x * x, n / 2);
  }
  else
  {
    return x * power(x, n - 1);
  }
}

double myPow(double x, int n)
{
  // your code goes here
  long long num = n;
  if (num < 0)
  {
    return power(1 / x, -1 * num);
  }
  else
  {
    return power(x, num);
  }
}

double myPowBetter(double x, int n)
{
  // your code goes here
  if (n == 0)
    return 1.0;
  if (n == 1)
    return x;

  long long num = n;
  if (n < 0)
  {
    x = 1 / x;
    num = -num;
  }
  double ans = 1.0;
  while (num > 0)
  {
    if (num % 2 == 1)
    {
      ans = ans * x;
      num = num - 1;
    }
    else
    {
      x = x * x;
      num = num / 2;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
}