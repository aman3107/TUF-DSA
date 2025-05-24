#include <bits/stdc++.h>
using namespace std;
int characterReplacementBetter(string s, int k)
{
  int l = 0;
  int r = 0;
  int maxLen = 0;
  int maxFreq = 0;
  int n = s.size();
  int hash[26] = {0};
  while (r < n)
  {
    hash[s[r] - 'A']++;
    maxFreq = max(maxFreq, hash[s[r] - 'A']);
    while ((r - l + 1) - maxFreq > k)
    {
      hash[s[l] - 'A']--;
      maxFreq = 0;
      for (int i = 0; i < 26; i++)
      {
        maxFreq = max(maxFreq, hash[i]);
      }
      l++;
    }

    maxLen = max(maxLen, r - l + 1);

    r++;
  }
  return maxLen;
}

int characterReplacementBrute(string s, int k)
{
  // your code goes here
  int maxLen = 0;
  int n = s.size();
  int maxFreq = 0;
  for (int i = 0; i < n; i++)
  {
    int hash[26] = {0};

    for (int j = i; j < n; j++)
    {
      hash[s[j] - 'A']++;
      maxFreq = max(maxFreq, hash[s[j] - 'A']);
      int changes = (j - i + 1) - maxFreq;
      if (changes <= k)
      {
        maxLen = max(maxLen, j - i + 1);
      }
      else
        break;
    }
  }
  return maxLen;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;

  cout << characterReplacementBetter(s, k) << endl;
}