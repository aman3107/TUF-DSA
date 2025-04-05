#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix)
{
  int n = matrix.size() - 1;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {

      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  for (int i = 0; i <= n; i++)
  {
    int left = 0;
    int right = n;
    while (left < right)
    {
      int temp = matrix[i][left];
      matrix[i][left] = matrix[i][right];
      matrix[i][right] = temp;
      left++;
      right--;
    }
  }
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
  rotateMatrix(v);
  for (auto nums : v)
  {
    for (auto num : nums)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}