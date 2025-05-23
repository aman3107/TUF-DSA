#include <bits/stdc++.h>
using namespace std;

int totalFruitsBetter(vector<int> &fruits)
{
  // your code goes here
  int r = 0;
  int l = 0;
  int n = fruits.size();
  int maxLen = 0;
  unordered_map<int, int> ump;
  while (r < n)
  {
    ump[fruits[r]]++;
    if (ump.size() > 2)
    {
      ump[fruits[l]]--;
      if (ump[fruits[l]] == 0)
      {
        ump.erase(fruits[l]);
      }
      l++;
    }
    if (ump.size() <= 2)
    {
      int len = r - l + 1;
      maxLen = max(maxLen, len);
    }
    r++;
  }
  return maxLen;
}

int totalFruitsBrute(vector<int> &fruits)
{
  // your code goes here
  int n = fruits.size();
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    unordered_set<int> basket;
    for (int j = i; j < n; j++)
    {
      basket.insert(fruits[j]);
      if (basket.size() > 2)
      {
        break;
      }
      else
      {

        int len = j - i + 1;
        maxLen = max(maxLen, len);
      }
    }
  }
  return maxLen;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  cout << totalFruitsBrute(arr) << endl;
}