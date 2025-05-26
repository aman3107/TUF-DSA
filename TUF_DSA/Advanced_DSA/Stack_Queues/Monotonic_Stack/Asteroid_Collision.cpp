#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      ans.push_back(arr[i]);
    }
    else
    {
      int val = abs(arr[i]);

      while (!ans.empty() && ans.back() > 0 && val > ans.back())
      {
        ans.pop_back();
      }
      if (!ans.empty() && ans.back() == val)
      {
        ans.pop_back();
      }
      else if (ans.empty() || ans.back() < 0)
      {
        ans.push_back(arr[i]);
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  vector<int> ans = asteroidCollision(arr);
  for (int it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}