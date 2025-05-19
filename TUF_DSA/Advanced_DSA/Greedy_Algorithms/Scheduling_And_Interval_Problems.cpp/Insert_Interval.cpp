#include <bits/stdc++.h>
using namespace std;
// bool comparator(vector<int> a, vector<int> b)
// {
//   return a[1] < b[1];
// }

// int MaximumNonOverlappingIntervals(vector<vector<int>> &Intervals)
// {
//   // your code goes here
//   int n = Intervals.size();
//   sort(Intervals.begin(), Intervals.end(), comparator);
//   int sequence = Intervals[0][1];
//   int cnt = 1;
//   for (int i = 1; i < n; i++)
//   {
//     if (Intervals[i][0] >= sequence)
//     {
//       cnt++;
//       sequence = Intervals[i][1];
//     }
//   }
//   return n - cnt;
// }

vector<vector<int>> insertNewInterval(vector<vector<int>> &Intervals, vector<int> &newInterval)
{
  // your code goes here
  int n = Intervals.size();
  vector<vector<int>> ans;
  int i = 0;
  while (i < n)
  {
    if (Intervals[i][1] >= newInterval[0])
    {
      break;
    }
    ans.push_back(Intervals[i]);
    i++;
  }
  while (i < n)
  {
    if (Intervals[i][0] > newInterval[1])
    {
      break;
    }
    newInterval[0] = min(newInterval[0], Intervals[i][0]);
    newInterval[1] = max(newInterval[1], Intervals[i][1]);
    i++;
  }
  ans.push_back(newInterval);
  while (i < n)
  {
    ans.push_back(Intervals[i]);
    i++;
  }
  return ans;
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
  vector<int> newInterval;
  for (int i = 0; i < 2; i++)
  {
    int data;
    cin >> data;
    newInterval.push_back(data);
  }
  vector<vector<int>> ans = insertNewInterval(intervals, newInterval);
  for (auto it : ans)
  {
    cout << it[0] << " " << it[1] << endl;
  }
}