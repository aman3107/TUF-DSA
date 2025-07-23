#include <bits/stdc++.h>
using namespace std;

/*
What is the Prefix Array / LPS (Longest Prefix Suffix)?
For a string s, the prefix array lps[i] stores the length of the longest proper prefix which is also a suffix for the substring s[0...i].

A prefix is a substring that starts at index 0.
A suffix is a substring that ends at index i.
Proper means it cannot be the entire string itself.

Intuition

The optimal solution includes forming the LPS array using an optimized approach. To optimize the LPS computation, we must:

Avoid recomputing prefix-suffix matches from scratch for every index.
Use previously computed LPS values to efficiently extend the matches.

The key idea will be two use two pointers - i and j:
i: Iterates through the string.
j: Tracks the length of the longest prefix which is also a suffix.

Now, there can be two scenarios when we compare s[i] and s[j], where s is the combined string formed. Let us understand both the scenarios in detail.
Scenario 1: When s[i] == s[j]
Consider the following example:

Assume that we have already computed the LPS array for the indices 0 to 4. Now, we are at index 5 (i == 5) and we want to find LPS[5].

Understanding:
i and j represents that the prefix of string s (s[0...j-1]) matches with the suffix of the string s[0...i-1]. (Since "a" matches as prefix as well as suffix in "abca", thus j = 1, which is length of "a")
Now if we found s[i] and s[j] to be equal, this means the next character in the prefix (s[j]) is also matching with the next character in the suffix (s[i]).
Hence, we increase both j and i, indicating that the prefix-suffix match is now longer by one character. Thus, setting LPS[i] = j+1.

Thus, If s[i] == s[j], it means that we have successfully extended an existing prefix-suffix match.
Scenario 2: When s[i] != s[j]
If s[i] ≠ s[j], we need to backtrack j without resetting it to 0 immediately. Instead, we use LPS[j-1] to find the next possible matching prefix.

Why backtrack to LPS[j-1]? The value LPS[j-1] tells us the longest proper prefix that is also a suffix of the prefix ending at index j-1. If s[i] does not match s[j], then instead of rechecking from j = 0, we can check from LPS[j-1].

Consider the following example:

Assume that we have already computed the LPS array for the indices 0 to 4. Now, we are at index 5 (i == 5) and we want to find LPS[5].

Understanding:
Here, LPS[2] = 1 means that the longest prefix which is also a suffix till index 2 is "a" (having length 1).
So we check if the next best prefix match can be extended from j = 1 instead of restarting j from 0.

Thus, if s[i] != s[j], it means that we must backtrack j to LPS[j-1] to find the next possible matching prefix. This leverages the previously computed LPS values to avoid redundant comparisons.
Approach:

Combine Pattern and Text using a delimiter forming a combined string. Compute the LPS array for the combined string. To compute the LPS array:
Initialize the LPS array with the first value as 0 and a pointer (j) to track the length of the longest prefix suffix.
Traverse the string and compare the current character with the character at the tracked position.
If they match, extend the prefix-suffix length by updating the LPS value and moving both pointers forward.
If they do not match and the tracked position is greater than 0, backtrack using the previously computed LPS value.
If no match is found after backtracking, set the LPS value to 0 and move to the next character.
Iterate through the portion of the combined string corresponding to the text. If the LPS value equals the length of the pattern, it signifies a match at the corresponding position in the text.
Store the indices where the pattern matches and return the result.
*/

vector<int> prefixArrayBrute(string s)
{
  int n = s.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      if (s.substr(0, j) == s.substr(i - j, i))
      {
        lps[i] = j;
      }
    }
  }
  return lps;
}

vector<int> prefixArray(string s)
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
  return lps;
}

vector<int> search(string pat, string txt)
{
  int n = txt.size();
  int m = pat.size();
  string s = pat + '$' + txt;
  vector<int> lps = prefixArray(s);
  vector<int> ans;
  for (int i = m + 1; i < s.size(); i++)
  {
    if (lps[i] == m)
    {
      ans.push_back(i - 2 * m);
    }
  }
  return ans;
}

int main()
{
  string txt, pat;
  cin >> txt >> pat;
  vector<int> ans = search(pat, txt);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}