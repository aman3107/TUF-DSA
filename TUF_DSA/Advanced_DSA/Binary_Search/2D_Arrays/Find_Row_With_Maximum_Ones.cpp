#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x)
{
  int low = 0;
  int high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int rowWithMax1s(vector<vector<int>> &mat)
{
  int maxCount = 0;
  int index = -1;
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n; i++)
  {
    int countOnes = m - lowerBound(mat[i], m, 1);
    if (countOnes > maxCount)
    {
      maxCount = countOnes;
      index = i;
    }
  }
  return index;
}

int rowWithMax1sBrute(vector<vector<int>> &mat)
{
  int maxCount = 0;
  int index = -1;
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n; i++)
  {
    int countOnes = 0;
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == 1)
      {
        countOnes++;
      }
    }
    if (countOnes > maxCount)
    {
      maxCount = countOnes;
      index = i;
    }
  }
  return index;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat;
  for (int i = 0; i < n; i++)
  {
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
      int val;
      cin >> val;
      v.push_back(val);
    }
    mat.push_back(v);
  }
  cout << rowWithMax1s(mat) << endl;
}