#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string nums, int k)
{
  int n = nums.size();
  if (n == k)
  {
    return "0";
  }
  stack<char> st;
  string ans = "";

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && k > 0 && (st.top() - '0') > (nums[i] - '0'))
    {
      st.pop();
      k--;
    }
    st.push(nums[i]);
  }
  while (!st.empty() && k > 0)
  {
    st.pop();
    k--;
  }
  if (st.empty())
  {
    return "0";
  }
  string res = "";
  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }
  while (res.size() > 0 && res.back() == '0')
  {
    res.pop_back();
  }
  if (res.empty())
  {
    return "0";
  }
  reverse(res.begin(), res.end());
  return res;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << removeKdigits(s, k) << endl;
}