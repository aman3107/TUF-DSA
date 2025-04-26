#include <bits/stdc++.h>
using namespace std;

void generateParenthesisHelper(int ind, int n, string str, int o, int c, vector<string> &ans)
{
  if (o > n)
  {
    return;
  }
  if (ind == 2 * n)
  {
    if (o == c)
    {
      ans.push_back(str);
    }
    return;
  }

  generateParenthesisHelper(ind + 1, n, str + "(", o + 1, c, ans);
  if (o > c)
  {
    generateParenthesisHelper(ind + 1, n, str + ")", o, c + 1, ans);
  }
}

vector<string> generateParenthesis(int n)
{
  // your code goes here
  string str = "";
  vector<string> ans;
  generateParenthesisHelper(0, n, str, 0, 0, ans);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> ans = generateParenthesis(n);
  for (auto st : ans)
  {
    cout << st << endl;
  }
}