#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, int newColor, int initialColor, int n, int m)
{
  if (row < 0 || row >= n || col < 0 || col >= m || image[row][col] != initialColor)
  {
    return;
  }
  image[row][col] = newColor;
  dfs(row - 1, col, image, newColor, initialColor, n, m);
  dfs(row + 1, col, image, newColor, initialColor, n, m);
  dfs(row, col - 1, image, newColor, initialColor, n, m);
  dfs(row, col + 1, image, newColor, initialColor, n, m);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
  int n = image.size();
  int m = image[0].size();
  vector<vector<int>> grid = image;

  int initialColor = grid[sr][sc];
  if (initialColor == newColor)
  {
    return image;
  }

  dfs(sr, sc, grid, newColor, initialColor, n, m);
  return grid;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    adj.push_back(temp);
  }
  cout << "Enter sr, sc, newColor" << endl;
  int sr, sc, newColor;
  cin >> sr >> sc >> newColor;
  vector<vector<int>> ans = floodFill(adj, sr, sc, newColor);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}