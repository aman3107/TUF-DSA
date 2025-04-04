#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  int srow = 0;
  int scol = 0;
  int erow = matrix.size() - 1;
  int ecol = matrix[0].size() - 1;
  vector<int> ans;
  while (srow <= erow && scol <= ecol)
  {
    for (int i = scol; i <= ecol; i++)
    {
      ans.push_back(matrix[srow][i]);
    }
    srow++;
    for (int i = srow; i <= erow; i++)
    {
      ans.push_back(matrix[i][ecol]);
    }
    ecol--;
    if (srow <= erow)
    {
      for (int i = ecol; i >= scol; i--)
      {
        ans.push_back(matrix[erow][i]);
      }
      erow--;
    }
    if (scol <= ecol)
    {
      for (int i = erow; i >= srow; i--)
      {
        ans.push_back(matrix[i][scol]);
      }
      scol++;
    }
  }
  return ans;

  // TC = O(nm)
  // SC = O(nm)
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int val;
      cin >> val;
      temp.push_back(val);
    }
    v.push_back(temp);
  }
  vector<int> ans = spiralOrder(v);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
  // for (auto nums : v)
  // {
  //   for (auto num : nums)
  //   {
  //     cout << num << " ";
  //   }
  //   cout << endl;
  // }
}