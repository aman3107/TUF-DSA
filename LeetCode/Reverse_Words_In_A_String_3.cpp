#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void reverse(int l, int r, string &s)
  {
    while (l <= r)
    {
      char temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
  }

public:
  string reverseWords(string s)
  {
    vector<int> arr;
    arr.push_back(-1);
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == ' ')
      {
        arr.push_back(i);
      }
    }
    arr.push_back(s.size());
    for (int i = 0; i < arr.size() - 1; i++)
    {
      int l = arr[i] + 1;
      int r = arr[i + 1] - 1;
      reverse(l, r, s);
    }
    return s;
  }
};