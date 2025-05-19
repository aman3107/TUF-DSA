#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &Arrival, vector<int> &Departure)
{
  sort(Arrival.begin(), Arrival.end());
  sort(Departure.begin(), Departure.end());

  int i = 0;
  int j = 0;
  int cnt = 0;
  int maxCnt = 0;
  int n = Arrival.size();
  while (i < n && j < n)
  {
    if (Arrival[i] <= Departure[j])
    {
      cnt++;
      i++;
    }
    else
    {
      cnt--;
      j++;
    }
    maxCnt = max(maxCnt, cnt);
  }
  return maxCnt;
}

int findPlatformBrute(vector<int> &Arrival, vector<int> &Departure)
{
  // your code goes here
  int n = Arrival.size();
  int maxCnt = 1;
  for (int i = 0; i < n; i++)
  {
    int cnt = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        if ((Arrival[i] >= Arrival[j] &&
             Departure[j] >= Arrival[i]))
        {
          cnt++;
        }
            }
    }
    maxCnt = max(maxCnt, cnt);
  }
  return maxCnt;
}

int main()
{
  int n;
  cin >> n;

  vector<int> arrival;
  vector<int> departure;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arrival.push_back(data);
  }
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    departure.push_back(data);
  }

  cout << findPlatform(arrival, departure) << endl;
}