#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &start, pair<int, int> &end)
{
  return start.second < end.second;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
  // your code goes here
  int n = start.size();
  vector<pair<int, int>> meetings;
  for (int i = 0; i < n; i++)
  {
    meetings.push_back({start[i], end[i]});
  }
  sort(meetings.begin(), meetings.end(), comparator);
  int limit = meetings[0].second;
  int cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (meetings[i].first > limit)
    {
      cnt++;
      limit = meetings[i].second;
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<int> start;
  vector<int> end;

  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    start.push_back(data);
  }
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    end.push_back(data);
  }

  cout << maxMeetings(start, end);
}