#include <bits/stdc++.h>
using namespace std;

int minFlipBits(int start, int goal)
{
  int ans = start ^ goal;
  int count = __builtin_popcount(ans);
  return count;
}

int main()
{
  int start;
  int goal;
  cin >> start >> goal;
  cout << minFlipBits(start, goal) << endl;
}