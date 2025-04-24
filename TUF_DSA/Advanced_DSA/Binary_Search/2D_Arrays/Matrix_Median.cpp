#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int n, int x)
{
  int ans = n;
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] > x)
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

int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    count += upperBound(mat[i], m, x);
  }
  return count;
}

int findMedian(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  int low = INT_MAX;
  int high = INT_MIN;
  int req = (n * m) / 2;
  for (int i = 0; i < n; i++)
  {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int smallEqual = countSmallEqual(matrix, n, m, mid);
    if (smallEqual <= req)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

int findMedianBrute(vector<vector<int>> &matrix)
{
  vector<int> mat;
  int n = matrix.size();
  int m = matrix[0].size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      mat.push_back(matrix[i][j]);
    }
  }
  sort(mat.begin(), mat.end());
  int median = (n * m) / 2;
  return mat[median];
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
  cout << findMedianBrute(mat) << endl;
}