#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b)
{
  return a[2] > b[2];
}

bool comparator1(pair<int, int> &a, pair<int, int> &b)
{
  return a.second > b.second;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
  // code here
  int n = profit.size();
  vector<pair<int, int>> jobs;
  for (int i = 0; i < n; i++)
  {
    jobs.push_back({deadline[i], profit[i]});
  }
  sort(jobs.begin(), jobs.end(), comparator1);
  int cntProfit = 0;
  int cnt = 0;
  int maxDeadline = -1;

  for (int i = 0; i < n; i++)
  {
    maxDeadline = max(maxDeadline, jobs[i].first);
  }
  vector<int> id(maxDeadline + 1, -1);
  for (int i = 0; i < n; i++)
  {
    for (int j = jobs[i].first - 1; j >= 0; j--)
    {
      if (id[j] == -1)
      {
        cnt++;
        id[j] = 0;
        cntProfit += jobs[i].second;
        break;
      }
    }
  }
  return {cnt, cntProfit};
}

vector<int> JobScheduling2(vector<vector<int>> &Jobs)
{
  sort(Jobs.begin(), Jobs.end(), comparator);
  int maxDeadline = -1;
  int n = Jobs.size();
  for (int i = 0; i < n; i++)
  {
    maxDeadline = max(maxDeadline, Jobs[i][1]);
  }

  vector<int> id(maxDeadline + 1, -1);
  int cntProfit = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int jobid = Jobs[i][0];
    int deadline = Jobs[i][1];
    int profit = Jobs[i][2];
    for (int j = deadline - 1; j >= 0; j--)
    {
      if (id[j] == -1)
      {
        cnt++;
        id[j] = jobid;
        cntProfit += profit;
        break;
      }
    }
  }
  return {cnt, cntProfit};
}

vector<int> JobScheduling(vector<vector<int>> &Jobs)
{
  // your code goes here

  sort(Jobs.begin(), Jobs.end(), comparator);
  int maxDeadline = -1;
  int n = Jobs.size();
  for (int i = 0; i < n; i++)
  {
    maxDeadline = max(maxDeadline, Jobs[i][1]);
  }

  vector<int> id(maxDeadline + 1, -1);
  int cntProfit = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int jobid = Jobs[i][0];
    int deadline = Jobs[i][1] - 1;
    int profit = Jobs[i][2];
    if (id[deadline] == -1)
    {
      id[deadline] = jobid;
      cntProfit += profit;
      cnt++;
    }
    else
    {
      int j = deadline;
      while (j >= 0)
      {
        if (id[j] == -1)
        {
          id[j] = jobid;
          cntProfit += profit;
          cnt++;
          break;
        }
        j--;
      }
    }
  }
  return {cnt, cntProfit};
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> jobs;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    jobs.push_back(temp);
  }

  vector<int> ans = JobScheduling(jobs);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}