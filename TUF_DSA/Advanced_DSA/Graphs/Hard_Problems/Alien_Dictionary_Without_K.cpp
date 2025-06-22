#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string findOrder(vector<string> &dict)
  {
    // code here
    int N = dict.size();
    vector<bool> present(26, false);
    for (auto &word : dict)
      for (char c : word)
        present[c - 'a'] = true;

    vector<int> adj[26];
    for (int i = 0; i < N - 1; i++)
    {
      string &str1 = dict[i], &str2 = dict[i + 1];
      int len = min(str1.size(), str2.size());
      bool found = false;
      for (int j = 0; j < len; j++)
      {
        if (str1[j] != str2[j])
        {
          adj[str1[j] - 'a'].push_back(str2[j] - 'a');
          found = true;
          break;
        }
      }
      if (!found && str1.size() > str2.size())
        return ""; // Invalid order (prefix issue)
    }

    vector<int> indegree(26, 0);
    for (int i = 0; i < 26; i++)
      for (int it : adj[i])
        indegree[it]++;

    queue<int> q;
    for (int i = 0; i < 26; i++)
      if (indegree[i] == 0 && present[i])
        q.push(i);

    string ans = "";
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      ans += (char)(node + 'a');
      for (int it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }

    if (ans.size() < count(present.begin(), present.end(), true))
      return ""; // Cycle detected

    return ans;
  }
};