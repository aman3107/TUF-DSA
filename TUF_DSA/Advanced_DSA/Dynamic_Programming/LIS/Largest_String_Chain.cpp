#include <bits/stdc++.h>
using namespace std;

/*
Sorted the words by length using comp().

Used a correct compare() function to check if one word can be formed by inserting one character into another.

Applied Dynamic Programming to compute the maximum chain length.

🧠 Quick Recap of Logic
For each word, you compare it with all shorter words before it.

If the shorter word is a valid predecessor (can form the current word by adding one character), you update the DP array.

Finally, you track and return the maximum value in the DP array*/

bool compare(string &s1, string &s2)
{
  // If difference is not 1 then return false
  if (s1.size() - s2.size() != 1)
  {
    return false;
  }
  int l1 = 0;
  int l2 = 0;
  // Check if s2 is missing 1 word from s1
  while (l1 < s1.size())
  {
    if (l2 < s2.size() && s1[l1] == s2[l2])
    {
      l1++;
      l2++;
    }
    else
    {
      l1++;
    }
  }
  // if both the string is standing at the end then return true
  if (l1 == s1.size() && l2 == s2.size())
    return true;
  return false;
}

static bool comp(string &s1, string &s2)
{
  // Sorting based on string length in increasing order
  return s1.size() < s2.size();
}

int longestStringChain(vector<string> &words)
{
  sort(words.begin(), words.end(), comp);
  int n = words.size();
  // Longest Increasing Subsequence till index i
  vector<int> dp(n, 1);
  int maxi = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (compare(words[i], words[j]) && 1 + dp[j] > dp[i])
      {
        dp[i] = 1 + dp[j];
      }
    }
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<string> arr;
  for (int i = 0; i < n; i++)
  {
    string data;
    cin >> data;
    arr.push_back(data);
  }
  cout << longestStringChain(arr) << endl;
}