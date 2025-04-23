#include <bits/stdc++.h>
using namespace std;

bool findTarget(vector<int> &arr, int n, int target)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      return true;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
  int n = mat.size();
  int m = mat[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  int low = 0;
  int high = n * m - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int row = mid / m;
    int col = mid % m;
    if (mat[row][col] == target)
    {
      return true;
    }
    else if (mat[row][col] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return false;
}

bool searchMatrixBetter(vector<vector<int>> &mat, int target)
{
  int n = mat.size();
  int m = mat[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  for (int i = 0; i < n; i++)
  {
    if (mat[i][0] <= target && target <= mat[i][m - 1])
    {
      return findTarget(mat[i], m, target);
    }
  }
  return false;
}

bool searchMatrixBrute(vector<vector<int>> &mat, int target)
{

  int n = mat.size();
  int m = mat[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == target)
      {
        return true;
      }
    }
  }
  return false;
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
  int target;
  cin >> target;
  cout << searchMatrixBetter(mat, target) << endl;
}