#include <bits/stdc++.h>
using namespace std;

int maxRectangle(vector<int> arr)
{
  int n = arr.size();
  int maxArea = 0;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] > arr[i])
    {
      int val = arr[st.top()];
      st.pop();
      int nse = i;
      int pse = !st.empty() ? st.top() : -1;
      int maxRect = val * (nse - pse - 1);
      maxArea = max(maxArea, maxRect);
    }
    st.push(i);
  }
  while (!st.empty())
  {
    int val = arr[st.top()];
    st.pop();
    int nse = n;
    int pse = !st.empty() ? st.top() : -1;
    int maxRect = val * (nse - pse - 1);
    maxArea = max(maxArea, maxRect);
  }
  return maxArea;
}

int maximalAreaOfSubMatrixOfAll2(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> prefixSum(n, vector<int>(m));
  for (int i = 0; i < m; i++)
  {
    int sum = 0;
    for (int j = 1; j < n; j++)
    {
      if (matrix[j][i] == 0)
      {
        prefixSum[j][i] = 0;
      }
      else
      {
        sum += matrix[i][j];
      }
      prefixSum[j][i] = sum;
    }
  }
  int maxArea = 0;
  for (int i = 0; i < n; i++)
  {
    maxArea = max(maxArea, maxRectangle(matrix[i]));
  }
  return maxArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  for (int i = 0; i < m; i++)
  {
    int sum = 0;
    for (int j = 1; j < n; j++)
    {
      if (matrix[j][i] == 0)
      {
        matrix[j][i] = 0;
      }
      else
      {
        matrix[j][i] = matrix[j - 1][i] + matrix[j][i];
      }
    }
  }
  int maxArea = 0;
  for (int i = 0; i < n; i++)
  {
    maxArea = max(maxArea, maxRectangle(matrix[i]));
  }
  return maxArea;
}

int main()
{
  int n;
  int m;
  cin >> n >> m;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    arr.push_back(temp);
  }

  cout << maximalAreaOfSubMatrixOfAll1(arr) << endl;
}