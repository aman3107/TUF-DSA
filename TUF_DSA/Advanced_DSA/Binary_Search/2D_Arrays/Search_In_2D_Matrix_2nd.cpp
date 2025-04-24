#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &nums, int n, int target)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
      return true;
    }
    else if (nums[mid] < target)
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

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  int row = 0;
  int col = m - 1;
  while (row < n && col >= 0)
  {
    if (matrix[row][col] == target)
    {
      return true;
    }
    else if (matrix[row][col] < target)
    {
      row++;
    }
    else
    {
      col--;
    }
  }
  return false;
}

bool searchMatrixBetter(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  for (int i = 0; i < n; i++)
  {

    bool ans = binarySearch(matrix[i], m, target);
    if (ans == true)
    {
      return true;
    }
  }
  return false;
}

bool searchMatrixBrute(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  if (n == 0 || m == 0)
  {
    return false;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == target)
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
  cout << searchMatrix(mat, target) << endl;
}