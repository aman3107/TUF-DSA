#include <bits/stdc++.h>
using namespace std;

/*
We want to know — at each position i — what's the maximum length of the prefix that is also a suffix for the substring s[0...i].

We use:

lps[i] → length of longest proper prefix which is also a suffix of s[0..i]

j → tracks how many characters of the prefix have matched

🔄 Approach Breakdown
Initialize LPS array with 0s.

Start from i = 1 (because LPS of 0th character is always 0).

If s[i] == s[j]:
→ We extend the current prefix-suffix match
→ Set lps[i] = j + 1, increment j.

If s[i] != s[j]:
→ While j > 0 and mismatch happens, backtrack j using lps[j-1]
→ Then retry match
→ If match happens again, set lps[i] = j + 1, increment j.
*/

vector<int> prefixSuffix(string s)
{

  // length of the string
  int n = s.size();

  // Create a lps(Longest Prefix Suffix) array
  vector<int> lps(n, 0);

  int j = 0;
  // checking all characters
  for (int i = 1; i < n; i++)
  {
    // When characters matched;
    if (s[i] == s[j])
    {
      lps[i] = j + 1;
      j++;
    }
    // When characters not matched
    else
    {
      while (j > 0 && s[i] != s[j])
      {
        j = lps[j - 1];
      }
      if (s[i] == s[j])
      {
        lps[i] = j + 1;
        j++;
      }
    }
  }
  return lps;
}

string shortestPalindrome(string s)
{
}

int main()
{
}