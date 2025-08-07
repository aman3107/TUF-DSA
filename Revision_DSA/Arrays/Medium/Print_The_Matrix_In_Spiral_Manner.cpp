#include <bits/stdc++.h>
using namespace std;

/*
🔍 Intuition:
We are given a 2D matrix and need to return all elements in spiral order.
That means we traverse the matrix in this sequence:
Top row (left to right)
Right column (top to bottom)
Bottom row (right to left)
Left column (bottom to top)
Repeat this pattern by shrinking the boundaries until all elements are covered.

🧠 Approach:
Initialize boundaries:
sr = starting row (0), er = ending row (n - 1)
sc = starting column (0), ec = ending column (m - 1)
c = counter to track how many elements we've added
total = total number of elements (n * m)
Traverse the matrix in layers, moving inward:
Left → Right (top row): row = sr, columns from sc to ec
Top → Bottom (right column): col = ec, rows from sr+1 to er
Right → Left (bottom row): row = er, columns from ec-1 to sc (only if rows remain)
Bottom → Top (left column): col = sc, rows from er-1 to sr+1 (only if columns remain)
After each direction, update the corresponding boundary (sr, er, sc, or ec).
Break the loop once all elements (total) are pushed into the answer.

✅ Time & Space Complexity:
Time: O(n * m) – Every element is visited once.

Space: O(n * m) – To store the result.
*/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  vector<int> ans;
  int c = 0;
  int n = matrix.size();
  int m = matrix[0].size();
  int sr = 0;
  int er = n - 1;
  int sc = 0;
  int ec = m - 1;
  int total = n * m;
  while (c < total)
  {
    for (int i = sc; i <= ec; i++)
    {
      ans.push_back(matrix[sr][i]);
      c++;
    }
    sr++;
    for (int i = sr; i <= er; i++)
    {
      ans.push_back(matrix[i][ec]);
      c++;
    }
    ec--;
    if (sr <= er)
    {
      for (int i = ec; i >= sc; i--)
      {
        ans.push_back(matrix[er][i]);
        c++;
      }
    }
    er--;
    if (sc <= ec)
    {
      for (int i = er; i >= sr; i--)
      {
        ans.push_back(matrix[i][sc]);
        c++;
      }
    }
    sc++;
  }
  return ans;
}

int main()
{
  int n, m;
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
  vector<int> ans = spiralOrder(arr);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}