#include <bits/stdc++.h>
using namespace std;

void reverse(int l, int r, string &s)
{
  while (l < r)
  {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    l++;
    r--;
  }
}

string reverseWords(string s)
{
  int n = s.size();
  int l = 0;
  int r = n - 1;
  reverse(l, r, s);
  int i = 0, j = 0, start = 0, end = 0;
  while (j < n)
  {
    while (j < n && s[j] == ' ') // Skip Spaces
      j++;
    if (j == n) // If  all are spaces
      break;
    start = i;                   // New word starts at i
    while (j < n && s[j] != ' ') // Copy the word forward
    {
      s[i++] = s[j++];
    }
    end = i - 1; // New word ends at i-1
    reverse(start, end, s);
    if (j < n)
    {
      s[i++] = ' '; // Add a single space between words
    }
  }
  return s.substr(0, end + 1);
}

int main()
{
  string s;
  getline(cin, s);
  cout << reverseWords(s) << endl;
}