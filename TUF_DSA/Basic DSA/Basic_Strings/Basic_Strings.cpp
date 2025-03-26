#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
  // your code goes here
  int left = 0;
  int right = s.size() - 1;
  while (left < right)
  {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
  }
  // TC = O(n)
  // SC = O(1)
}

bool palindromeCheck(string &s)
{
  // your code goes here
  int left = 0;
  int right = s.size() - 1;
  while (left < right)
  {
    if (s[left] != s[right])
    {
      return false;
    }
    left++;
    right--;
  }
  return true;

  // TC = O(n)
  // SC = O(1)
}

string largeOddNum(string &s)
{
  // your code goes here
  int ind = -1;
  int i;
  for (i = s.size() - 1; i >= 0; i--)
  {
    if ((s[i] - '0') % 2 == 1)
    {
      ind = i;
      break;
    }
  }
  i = 0;
  while (i <= ind && s[i] == '0')
  {
    i++;
  }
  cout << i << " " << ind << endl;
  return s.substr(i, ind - i + 1);

  // TC = O(n)
  // SC = O(1)
}

string longestCommonPrefix(vector<string> &str)
{
  // your code goes here
  sort(str.begin(), str.end());
  string s1 = str[0];
  string s2 = str[str.size() - 1];
  int i;
  for (i = 0; i < s1.size() && i < s2.size(); i++)
  {
    if (s1[i] != s2[i])
    {
      break;
    }
  }
  return s1.substr(0, i);

  // TC = O(Nlogn)
  // SC = O(1)
}

bool rotateString(string &s, string &goal)
{
  // your code goes here
  if (s.length() != goal.length())
  {
    return false;
  }

  s = s + s;
  return s.find(goal) != string::npos;

  // TC = O(n)
  // SC = O(n)
}

bool isomorphicString(string s, string t)
{
  // your code goes here
  if (s.length() != t.length())
  {
    return false;
  }
  int hash1[26] = {0};
  int hash2[26] = {0};
  for (int i = 0; i < s.size(); i++)
  {
    if (hash1[s[i] - 'a'] != hash2[t[i] - 'a'])
    {
      return false;
    }
    hash1[s[i] - 'a']++;
    hash2[t[i] - 'a']++;
  }
  return true;
}

bool anagramStrings(string &s, string t)
{
  // your code goes here
  int hash1[26] = {0};
  int hash2[26] = {0};
  for (int i = 0; i < s.size(); i++)
  {
    hash1[s[i] - 'a']++;
    hash2[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (hash1[i] != hash2[i])
    {
      return false;
    }
  }
  return true;
  // TC = O(n)
  // SC = O(1)
}

bool comparator(pair<int, char> p1, pair<int, char> p2)
{
  if (p1.first > p2.first)
    return true;
  if (p1.first < p2.first)
    return false;
  return p1.second < p2.second;
}

vector<char> frequencySort(string &s)
{
  // your code goes here
  pair<int, char> freq[26];
  for (int i = 0; i < 26; i++)
  {
    freq[i] = {0, i + 'a'};
  }
  for (int i = 0; i < s.size(); i++)
  {
    freq[s[i] - 'a'].first++;
  }
  sort(freq, freq + 26, comparator);
  vector<char> ans;
  for (int i = 0; i < 26; i++)
  {
    if (freq[i].first > 0)
    {
      ans.push_back(freq[i].second);
    }
  }
  return ans;
}

int main()
{

  string s1, s2;
  cin >> s1 >> s2;
  // cout << rotateString(s1, s2) << endl;
  // cout << isomorphicString(s1, s2) << endl;
  cout << anagramStrings(s1, s2) << endl;

  /*
  vector<string> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    v.push_back(s);
  }

  cout << longestCommonPrefix(v) << endl;

  string s;
  cin >> s;
  cout << palindromeCheck(s) << endl;
  cout << largeOddNum(s) << endl;


  int n;
  cout << "Enter value of n :" << endl;
  cin >> n;

  vector<char> v;
  for (int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    v.push_back(c);
  }
  reverseString(v);
  for (auto a : v)
  {
    cout << a << " ";
  }
  cout << endl;
  */
}