#include "DisjointSet.h"

vector<vector<string>> accountsMerge(vector<vector<string>> accounts)
{
  int n = accounts.size();
  DisjointSet ds(n);
  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < accounts[i].size(); j++)
    {
      string email = accounts[i][j];
      if (mp.find(email) == mp.end())
      {
        mp[email] = i;
      }
      else
      {
        ds.unionBySize(i, mp[email]);
      }
    }
  }
  vector<string> mergedMail[n];
  for (auto it : mp)
  {
    string email = it.first;
    int node = ds.findUPar(it.second);
    mergedMail[node].push_back(email);
  }
  vector<vector<string>> ans;
  for (int i = 0; i < n; i++)
  {
    if (mergedMail[i].size() == 0)
      continue;
    sort(mergedMail[i].begin(), mergedMail[i].end());
    vector<string> temp;
    temp.push_back(accounts[i][0]);
    for (auto it : mergedMail[i])
    {
      temp.push_back(it);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<string>> accounts;
  for (int i = 0; i < n; i++)
  {
    vector<string> temp;
    for (int j = 0; j < m; j++)
    {
      string st;
      cin >> st;
      temp.push_back(st);
    }
    accounts.push_back(temp);
  }
  vector<vector<string>> ans = accountsMerge(accounts);
  for (auto it : ans)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
}