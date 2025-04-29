#include <bits/stdc++.h>
using namespace std;

void combinationSum3Helper(int sum, int last, vector<int> &temp, int k, vector<vector<int>> &ans)
{
  // your code goes here
  if (sum == 0 && temp.size() == k)
  {
    ans.push_back(temp);
    return;
  }
  if (sum <= 0 || temp.size() > k)
  {
    return;
  }

  for (int i = last; i <= 9; i++)
  {
    if (i <= sum)
    {
      temp.push_back(i);
      combinationSum3Helper(sum - i, i + 1, temp, k, ans);
      temp.pop_back();
    }
    else
    {
      break;
    }
  }
}

vector<vector<int>> combinationSum3(int k, int n)
{
  // your code goes here
  vector<vector<int>> ans;
  vector<int> temp;
  combinationSum3Helper(n, 1, temp, k, ans);
  return ans;
}

int main()
{
  int k;
  cin >> k;
  int n;
  cin >> n;
  vector<vector<int>> ans = combinationSum3(k, n);
  for (auto subArr : ans)
  {
    for (int el : subArr)
    {
      cout << el << " ";
    }
    cout << endl;
  }
}