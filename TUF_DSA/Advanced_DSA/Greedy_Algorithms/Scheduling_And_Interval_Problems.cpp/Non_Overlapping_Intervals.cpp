#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
  return a[1] < b[1];
}

int MaximumNonOverlappingIntervals(vector<vector<int>> &Intervals)
{
  // your code goes here
  int n = Intervals.size();
  sort(Intervals.begin(), Intervals.end(), comparator);
  int sequence = Intervals[0][1];
  int cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (Intervals[i][0] >= sequence)
    {
      cnt++;
      sequence = Intervals[i][1];
    }
  }
  return n - cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> intervals;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < 2; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    intervals.push_back(temp);
  }
  cout << MaximumNonOverlappingIntervals(intervals) << endl;
}