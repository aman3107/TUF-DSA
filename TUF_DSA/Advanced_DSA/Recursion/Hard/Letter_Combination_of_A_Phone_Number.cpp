#include <bits/stdc++.h>
using namespace std;

void keypadHelper(int n, vector<string> &ans, string output, unordered_map<int, string> &ump)
{
  if (n == 0)
  {
    ans.push_back(output);
    return;
  }

  int rem = n % 10;
  n = n / 10;
  string str = ump[rem];
  for (int i = 0; i < str.size(); i++)
  {
    keypadHelper(n, ans, str[i] + output, ump);
  }
}

vector<string> Keypad(int n)
{
  unordered_map<int, string> ump;
  ump[2] = "abc";
  ump[3] = "def";
  ump[4] = "ghi";
  ump[5] = "jkl";
  ump[6] = "mno";
  ump[7] = "pqrs";
  ump[8] = "tuv";
  ump[9] = "wxyz";
  vector<string> ans;
  keypadHelper(n, ans, "", ump);
  return ans;
}

void letterCombinationsHelper(int ind, string output, vector<string> &ans, string digits, string comboArr[])
{
  if (ind == digits.size())
  {
    ans.push_back(output);
    return;
  }

  int digit = digits[ind] - '0';
  string str = comboArr[digit];
  for (int i = 0; i < str.size(); i++)
  {
    letterCombinationsHelper(ind + 1, output + str[i], ans, digits, comboArr);
  }
}

vector<string> letterCombinations(string digits)
{
  // your code goes here
  vector<string> ans;
  if (digits.size() == 0)
  {
    return ans;
  }
  string comboArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  letterCombinationsHelper(0, "", ans, digits, comboArr);
  return ans;
}

int main()
{
  // int n;
  // cin >> n;

  // vector<string> str = Keypad(n);
  // for (string s : str)
  // {
  //   cout << s << " ";
  // }
  // cout << endl;

  string digits;
  cin >> digits;
  vector<string> str = letterCombinations(digits);
  for (string s : str)
  {
    cout << s << " ";
  }
  cout << endl;
}