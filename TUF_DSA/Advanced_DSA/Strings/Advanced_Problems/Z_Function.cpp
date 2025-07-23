#include <bits/stdc++.h>
using namespace std;

/*
Maintaining a Window
A window [left, right] is maintained where a valid prefix match exists.
If the current index i is inside this window, the Z-values from previously computed results are reused.
If i is outside the window, character comparisons are performed from scratch.
Reusing Previously Computed Z-values
If i is inside the window and the mirrored index i - left has a Z-value within bounds, reuse it (Z[i] = Z[i - left]).
Otherwise, extend the prefix match by checking characters beyond the window.
Extending the Match Beyond the Window
If the precomputed Z-value is not enough, brute force is used only beyond the window.
The new boundaries [left, right] are updated.

🧠 Intuition:
We use the Z-algorithm to efficiently search for occurrences of a pattern in a text in linear time O(n + m).
The Z-array for a string S stores at each index i the length of the longest substring starting at i which is also a prefix of S.
If we compute the Z-array for the string:
pattern + '$' + text
Then any position i in the Z-array with value equal to the length of the pattern (m) represents a match of the pattern in the text.

🧱 Approach:
✅ Step 1: Concatenate pattern, delimiter, and text
pattern = pattern + '$' + text;
This ensures that there's no overlap between pattern and text during comparison.
'$' is a special character that does not appear in either the pattern or text.

✅ Step 2: Compute Z-array for the combined string
vector<int> zAlgo(string s)
Maintain two pointers: l and r that define the current Z-box (window of known matches).

For each index i, we compute how much of the prefix s[0…] matches with s[i…].

We reuse previously computed results whenever i is within the current Z-box (i <= r) to avoid re-computation.

✅ Step 3: Identify pattern matches using Z-array

for (int i = m + 1; i < n + m; i++)
{
    if (zArr[i] == m)
        ans.push_back(i - m - 1);
}
We skip the first m + 1 characters (pattern + '$').

At each index i in the combined string, if the Z value is m, it means a full match of the pattern starts at i - m - 1 in the original text.

🚀 Z-Algorithm Intuition
The Z-algorithm is an efficient way to compute the Z-array in O(n) time. It maintains a window [l, r] — called a Z-box — where the substring s[l..r] matches the prefix s[0..(r−l)].

We iterate over the string and for each i:
If i is outside the current Z-box, do a brute-force match from i with the prefix.

If i is inside the current Z-box, reuse previously computed Z-values:

If the value is completely inside the window, copy it.

If it extends beyond the window, recompute from scratch.


*/

vector<int> zAlgo(string s)
{
  int n = s.size();
  vector<int> z(n, 0);
  // Pointers to mark the window
  int l = 0;
  int r = 0;
  // For every character
  for (int i = 1; i < n; i++)
  {
    // Case 1: i is outside the current Z-box
    if (i > r)
    {
      // Start comparing s[i..] with s[0..]
      while (i + z[i] < n && s[i + z[i]] == s[z[i]])
      {
        z[i]++;
      }
      // Update Z-box to the new match range
      l = i;
      r = i + z[i] - 1;
    }
    // Else (Inside the window)
    else
    {
      // Case 2a: Z[k] fits completely inside current Z-box
      if (i + z[i - l] <= r)
      {
        z[i] = z[i - l];
      }
      // Case 2b: Z[k] spills over current Z-box → recompute beyond boundary
      else
      {
        // Start with the remaining match length
        z[i] = r - i + 1;
        // Try to extend the match beyond r using brute force
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
        {
          z[i]++;
        }
        // Update the window
        l = i;
        r = i + z[i] - 1;
      }
    }
  }
  return z;
}

vector<int> search(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  string s = pattern + '$' + text;
  vector<int> zArr = zAlgo(s);
  vector<int> ans;
  for (int i = m + 1; i < s.size(); i++)
  {
    if (zArr[i] == m)
    {
      ans.push_back(i - m - 1);
    }
  }
  return ans; 
}

vector<int> searchBrute(string text, string pattern)
{
  int n = text.size();
  vector<int> arr(n, 0);
  for (int i = 1; i < n; i++)
  {
    int l = 0;
    int r = i;
    int cnt = 0;
    while (r < n && text[l] == text[r])
    {
      cnt++;
      r++;
      l++;
    }
    arr[i] = cnt;
  }
  return arr;
}

int main()
{
  string text, pattern;
  cin >> text >> pattern;
  vector<int> ans = search(text, pattern);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
}