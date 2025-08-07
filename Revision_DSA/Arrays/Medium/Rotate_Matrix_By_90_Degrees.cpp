#include <bits/stdc++.h>
using namespace std;

/*
 Intuition:
To rotate a matrix 90° clockwise, we follow two main steps:
Transpose the matrix – convert rows to columns.
Reverse each row – to get the correct rotated orientation.

🧠 Approach:
✅ Step 1: Transpose the Matrix
Transposing means converting matrix[i][j] to matrix[j][i].
We do this only for j > i to avoid double-swapping or reverting.
for (int row = 0; row < n; row++) {
    for (int col = row + 1; col < n; col++) {
        swap(matrix[row][col], matrix[col][row]);
    }
}
✅ Step 2: Reverse Each Row
After transpose, each row is reversed to simulate clockwise rotation.
for (int i = 0; i < n; i++) {
    reverse(0, n - 1, matrix[i]);  // using custom reverse function
}
🔁 Custom reverse() function
It reverses a 1D array (row) in-place between indices l and r:
while (l < r) {
    swap(arr[l], arr[r]);
    l++;
    r--;
}

Time and Space Complexity:
Time Complexity: O(n^2)
Transpose: O(n^2)
Reverse rows: O(n^2)
Space Complexity: O(1) — done in-place, no extra space used.
*/

void reverse(int l, int r, vector<int> &arr)
{
  while (l < r)
  {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    l++;
    r--;
  }
}

void rotateMatrix(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  for (int row = 0; row < n; row++)
  {
    for (int col = row + 1; col < n; col++)
    {
      swap(matrix[row][col], matrix[col][row]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    reverse(0, n - 1, matrix[i]);
  }
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
  rotateMatrix(arr);
  for (auto &it : arr)
  {
    for (auto &it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
}