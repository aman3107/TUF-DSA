#include <bits/stdc++.h>
using namespace std;

/*
Intuition
Given a string s, return the longest proper prefix of s which is also a suffix of s.
A proper prefix means it cannot be equal to the entire string itself.

This is a classic use-case of the KMP (Knuth-Morris-Pratt) prefix function. The lps array (Longest Prefix Suffix) helps us track the longest prefix which is also a suffix up to each position in the string.

We are interested in the last value of the LPS array:
It gives the length of the longest prefix which is also a suffix for the entire string.

Approach
Initialize an LPS (longest prefix-suffix) array of size n with all 0s.
Use two pointers:
i → current index scanning the string
j → length of the current longest prefix matched so far
Loop from i = 1 to n - 1:
If s[i] == s[j], we extend the current prefix-suffix match and increment j.
Else, if there's a mismatch:
Use previously computed LPS: j = lps[j - 1] until a match is found or j == 0.
Assign lps[i] = j.
Finally, the last value lps[n - 1] gives the length of the longest proper prefix which is also a suffix.
Return the substring s.substr(0, len).

Complexity
Time complexity:
TC = O(N)

Space complexity:
SC = O(N)


*/

class Solution
{
public:
  string longestPrefix(string s)
  {
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
      if (s[i] == s[j])
      {
        lps[i] = j + 1;
        j++;
      }
      else
      {
        while (j > 0 && s[j] != s[i])
        {
          j = lps[j - 1];
        }
        if (s[j] == s[i])
        {
          lps[i] = j + 1;
          j++;
        }
      }
    }
    int len = lps.back();
    return s.substr(0, len);
  }
};