#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings2(string s)
{
  int l = 0, r = 0;
  int n = s.size();
  int count = 0;
  int hash[3] = {0};
  while (r < n)
  {
    hash[s[r] - 'a']++;
    while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0)
    {
      count += n - r;
      hash[s[l] - 'a']--;
      l++;
    }
    r++;
  }
  return count;
}

int numberOfSubstrings(string s)
{
  int n = s.size();
  int hash[3] = {-1, -1, -1};
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    hash[s[i] - 'a'] = i;
    if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1)
    {
      count += 1 + min(hash[0], min(hash[1], hash[2]));
    }
  }
  return count;
}
int numberOfSubstringsBrute(string s)
{
  // your code goes here
  int n = s.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int hash[3] = {0};
    for (int j = i; j < n; j++)
    {
      hash[s[j] - 'a'] = 1;
      if (hash[0] + hash[1] + hash[2] == 3)
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  string s;
  cin >> s;
  cout << numberOfSubstrings(s) << endl;
}