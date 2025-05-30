#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> M)
{
  return M[a][b] == 1;
}

int findCelebrity(int n, vector<vector<int>> M)
{
  // Write your code here.
  int ans = 0;
  for (int i = 1; i < n; ++i)
  {
    if (knows(ans, i, M))
    {
      ans = i;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (ans != i)
    {
      if (knows(ans, i, M) || !knows(i, ans, M))
      {
        return -1;
      }
    }
  }
  return ans;
}

int celebrity(vector<vector<int>> &M)
{
  int n = M.size();
  int top = 0;
  int down = n - 1;
  while (top < down)
  {
    if (M[top][down] == 1)
    {
      top++;
    }
    else if (M[down][top] == 1)
    {
      down--;
    }
    else
    {
      top++;
      down--;
    }
  }
  if (top > down)
  {
    return -1;
  }
  for (int i = 0; i < n; i++)
  {
    if (i == top)
    {
      continue;
    }
    if (M[top][i] == 1 || M[i][top] == 0)
    {
      return -1;
    }
  }
  return top;
}

int celebrityBrute(vector<vector<int>> &M)
{
  int n = M.size();
  vector<int> knowMe(n, 0);
  vector<int> iKnow(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (M[i][j] == 1)
      {
        knowMe[j]++;
        iKnow[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (knowMe[i] == n - 1 && iKnow[i] == 0)
    {
      return i;
    }
  }

  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      int data;
      cin >> data;
      temp.push_back(data);
    }
    arr.push_back(temp);
  }
  cout << celebrity(arr) << endl;
}