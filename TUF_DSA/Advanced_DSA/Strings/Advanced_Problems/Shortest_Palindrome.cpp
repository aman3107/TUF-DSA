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


🧠 Intuition:
To convert a string into a palindrome with minimum characters added in front, we:
Find the longest prefix of the string which is already a palindrome.
The remaining part (i.e., the suffix that breaks the palindrome) should be reversed and prepended.

🔄 Approach:
We use the KMP prefix function (LPS array) to solve this efficiently.
Step-by-step:
Reverse the original string s.
Build a new string: str = s + '$' + reverse(s)
'$' is a delimiter to separate the original and reversed part.
Build the LPS array for this new string.
This tells us the length of the longest prefix of s that matches a suffix of reverse(s).
Take the unmatched suffix from reverse(s) and prepend it to original string s.

🧩 prefixSuffix() Function
This is a standard KMP prefix table computation, which gives you:

For any prefix s[0..i], lps[i] = length of the longest proper prefix which is also a suffix.

Used here to find how much of the original string is already a palindrome prefix.


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
  int n = s.size();
  string revs = s;
  // reverse the string
  reverse(revs.begin(), revs.end());
  // create a new string with the original string and reverse string
  string str = s + '$' + revs;
  // Create a lps array for this string
  vector<int> lps = prefixSuffix(str);
  // Take the length how many characters are not matched
  int len = n - lps.back();
  return revs.substr(0, len) + s;
}

int main()
{
  string s;
  cin >> s;
  cout << shortestPalindrome(s) << endl;
}