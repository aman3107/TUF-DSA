#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &mat, int col, int n)
{
  int maxEle = INT_MIN;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    if (mat[i][col] > maxEle)
    {
      maxEle = mat[i][col];
      index = i;
    }
  }
  return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int low = 0;
  int high = m - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int row = findMax(mat, mid, n);

    int left = mid > 0 ? mat[row][mid - 1] : INT_MIN;
    int right = mid < m - 1 ? mat[row][mid + 1] : INT_MIN;
    if (mat[row][mid] > left && mat[row][mid] > right)
    {
      return {row, mid};
    }
    else if (mat[row][mid] < right)
    {
      low = mid + 1;
    }

    else
    {
      high = mid - 1;
    }
  }
  return {-1, -1};
}

vector<int> findPeakGridBrute(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = (i != 0 ? mat[i - 1][j] : INT_MIN);
      int down = (i < n - 1 ? mat[i + 1][j] : INT_MIN);
      int left = (j != 0 ? mat[i][j - 1] : INT_MIN);
      int right = (j < m - 1 ? mat[i][j + 1] : INT_MIN);
      if (mat[i][j] > up && mat[i][j] > down && mat[i][j] > left && mat[i][j] > right)
      {
        return {i, j};
      }
    }
  }
  return {-1, -1};
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
  vector<int> ans = findPeakGridBrute(mat);
  for (int a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
}