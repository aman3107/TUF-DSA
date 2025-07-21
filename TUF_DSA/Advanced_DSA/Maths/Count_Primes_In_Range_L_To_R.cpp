#include <bits/stdc++.h>
using namespace std;

vector<int> primesInRange(vector<vector<int>> &queries)
{
  // your code goes here

  int n = 0;
  for (auto &it : queries)
  {
    n = max(n, it[1]);
  }
  vector<int> prime(n + 1, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= n; j += i)
      {
        prime[j] = 0;
      }
    }
  }

  vector<int> prefixSum(n + 1, 0);
  int count = 0;
  for (int i = 2; i <= n; i++)
  {
    count += prime[i];
    prefixSum[i] = count;
  }
  vector<int> ans;
  for (int i = 0; i < queries.size(); i++)
  {
    int l = queries[i][0];
    int r = queries[i][1];
    if (l == 0)
    {
      ans.push_back(prefixSum[r]);
    }
    else
    {
      ans.push_back(prefixSum[r] - prefixSum[l - 1]);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> nums;
  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    nums.push_back({l, r});
  }
  vector<int> ans = primesInRange(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}