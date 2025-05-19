#include <bits/stdc++.h>
using namespace std;

long long solveBrute(vector<int> &bt)
{
  // your code goes here
  int n = bt.size();
  sort(bt.begin(), bt.end());
  long long waitingTime = 0;
  long long totalTime = 0;
  for (int i = 0; i < n; i++)
  {
    waitingTime += totalTime;
    totalTime += bt[i];
  }
  return waitingTime / n;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    v.push_back(data);
  }
  cout << solveBrute(v) << endl;
}