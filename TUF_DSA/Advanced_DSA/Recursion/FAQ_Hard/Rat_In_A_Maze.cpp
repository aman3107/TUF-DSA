#include <bits/stdc++.h>
using namespace std;

void findPathHelper(vector<vector<int>> &grid, int r, int c, string word, vector<string> &ans)
{
  if (grid[r][c] == 0)
  {
    return;
  }
  if (r == grid.size() - 1 && c == grid.size() - 1)
  {
    ans.push_back(word);
    return;
  }

  grid[r][c] = 0;
  if (r - 1 >= 0)
  {
    findPathHelper(grid, r - 1, c, word + "U", ans);
  }
  if (c + 1 < grid.size())
  {
    findPathHelper(grid, r, c + 1, word + "R", ans);
  }
  if (r + 1 < grid.size())
  {
    findPathHelper(grid, r + 1, c, word + "D", ans);
  }
  if (c - 1 >= 0)
  {
    findPathHelper(grid, r, c - 1, word + "L", ans);
  }
  grid[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &grid)
{
  // your code goes here
  vector<string> ans;
  findPathHelper(grid, 0, 0, "", ans);
  return ans;
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
      int val;
      cin >> val;
      temp.push_back(val);
    }
    grid.push_back(temp);
  }

  vector<string> str = findPath(grid);
  for (string s : str)
  {
    cout << s << endl;
  }
}