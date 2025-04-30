#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int left, int right)
{
  while (left <= right)
  {
    if (s[left] != s[right])
    {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

void partitionHelper(int ind, vector<string> &temp, string &s, vector<vector<string>> &ans)
{
  // your code goes here
  if (ind == s.size())
  {
    ans.push_back(temp);
    return;
  }
  for (int j = ind; j < s.size(); j++)
  {
    if (isPalindrome(s, ind, j))
    {
      string subStr = s.substr(ind, j - ind + 1);
      temp.push_back(subStr);
      partitionHelper(j + 1, temp, s, ans);
      temp.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  // your code goes here
  vector<vector<string>> ans;
  vector<string> temp;
  partitionHelper(0, temp, s, ans);
  return ans;
}

int main()
{
  string s;
  cin >> s;
  vector<vector<string>> ans = partition(s);
  for (auto str : ans)
  {
    for (string s : str)
    {
      cout << s << " ";
    }
    cout << endl;
  }
}