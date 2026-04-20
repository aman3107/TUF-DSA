#include <bits/stdc++.h>
using namespace std;

bool isomorphicString(string s, string t)
{
  // your code goes here
  int hash1[256] = {0};
  int hash2[256] = {0};

  for (int i = 0; i < s.size(); i++)
  {
    if (hash1[s[i]] != hash2[t[i]])
      return false;
    hash1[s[i]] = i + 1;
    hash2[t[i]] = i + 1;
  }
  return true;
}

string longestCommonPrefix(vector<string> &str)
{
  // your code goes here
  if (str.size() == 0)
    return "";
  int n = str.size() - 1;
  sort(str.begin(), str.end());
  string first = str[0];
  string last = str[n];
  int minLen = min(first.size(), last.size());
  string ans = "";
  for (int i = 0; i < minLen; i++)
  {
    if (first[i] != last[i])
    {
      return ans;
    }
    ans += first[i];
  }
  return ans;
}

string largeOddNum(string &s)
{
  // your code goes here
  int ind = -1;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if ((s[i] - '0') % 2 == 1)
    {
      ind = i;
      break;
    }
  }
  int i = 0;
  while (i <= ind && (s[i] == '0'))
  {
    i++;
  }
  return s.substr(i, ind - i + 1);
}

bool palindromeCheck(string &s)
{
  // your code goes here
  int l = 0;
  int r = s.size() - 1;
  while (l < r)
  {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

void reverseString(vector<char> &s)
{
  int l = 0;
  int r = s.size() - 1;
  while (l < r)
  {
    char ch = s[l];
    s[l] = s[r];
    s[r] = ch;
    l++;
    r--;
  }
}

int main()
{
  int n;
  cin >> n;
  // vector<char> s;
  // for (int i = 0; i < n; i++)
  // {
  //   char ch;
  //   cin >> ch;
  //   s.push_back(ch);
  // }
  // reverseString(s);
  // for (auto it : s)
  // {
  //   cout << it << " ";
  // }

  // vector<string> s;
  // for (int i = 0; i < n; i++)
  // {
  //   string str;
  //   cin >> str;
  //   s.push_back(str);
  // }
  string s;
  string t;
  cin >> s;
  cin >> t;
  cout << isomorphicString(s, t);
}