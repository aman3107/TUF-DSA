#include "DisjointSet.h"

int largestIsland(vector<vector<int>> &grid)
{
  int n = grid.size();
  DisjointSet ds(n * n);
  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};

  // Step 1 Making components
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < n; col++)
    {
      if (grid[row][col] == 1)
      {
        for (int i = 0; i < 4; i++)
        {
          int nRow = row + delRow[i];
          int nCol = col + delCol[i];
          if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n)
          {
            if (grid[nRow][nCol] == 1)
            {
              int nodeNo = (row * n) + col;
              int adjNodeNo = (nRow * n) + nCol;
              ds.unionBySize(nodeNo, adjNodeNo);
            }
          }
        }
      }
    }
  }

  int largest = 0;

  // Step 2 converting all 0's to 1's and check for all 4 directions
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < n; col++)
    {
      if (grid[row][col] == 0)
      {
        unordered_set<int> st;
        for (int i = 0; i < 4; i++)
        {
          int nRow = row + delRow[i];
          int nCol = col + delCol[i];

          if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1)
          {
            int adjNodeNo = (nRow * n) + nCol;
            int uPar = ds.findUPar(adjNodeNo);
            st.insert(uPar);
          }
        }
        int sizeTotal = 0;
        for (auto it : st)
        {
          sizeTotal += ds.size[it];
        }
        largest = max(largest, sizeTotal + 1);
      }
    }
  }

  // Stpe 3 If matrix has all the 1's

  for (int i = 0; i < n * n; i++)
  {
    largest = max(largest, ds.size[ds.findUPar(i)]);
  }
  return largest;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    grid.push_back(temp);
  }
  cout << largestIsland(grid) << endl;
}