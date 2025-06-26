#include <bits/stdc++.h>
using namespace std;

// This algo will take less time complexity
int miniMumMultiplications(vector<int> &arr, int start, int end)
{
  if (start == end)
  {
    return 0;
  }
  queue<pair<int, int>> q;
  // Steps, num
  int mod = 1e5;
  vector<int> minSteps(1e5, INT_MAX);
  q.push({0, start});
  minSteps[start] = 0;
  while (!q.empty())
  {
    int steps = q.front().first;
    int node = q.front().second;
    q.pop();

    for (auto it : arr)
    {
      int num = (node * it) % mod;
      if (num == end)
      {
        return steps + 1;
      }
      if (minSteps[num] > steps + 1)
      {
        minSteps[num] = steps + 1;
        q.push({steps + 1, num});
      }
    }
  }
  return -1;
}

int minimumMultiplications(vector<int> &arr, int start, int end)
{
  if (start == end)
  {
    return 0;
  }
  queue<pair<int, int>> q;
  // steps, num
  int mod = 1e5;
  q.push({0, start});
  vector<int> visited(mod, 0);
  while (!q.empty())
  {
    int step = q.front().first;
    int node = q.front().second;
    q.pop();
    if (node == end)
    {
      return step;
    }
    for (auto it : arr)
    {
      int adjNode = (node * it) % mod;
      if (!visited[adjNode])
      {
        visited[adjNode] = 1;
        q.push({step + 1, adjNode});
      }
    }
  }
  return -1;
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
  cout << "Enter start and end " << endl;
  int start, end;
  cin >> start >> end;
  cout << minimumMultiplications(arr, start, end) << endl;
}