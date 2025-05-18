#include <bits/stdc++.h>
using namespace std;
int minJumps(vector<int> &arr, int n)
{
  // Write your code here.
  int maxReach = 0;
  int currReach = 0;
  int jump = 0;
  for (int i = 0; i < n; i++)
  {
    maxReach = max(maxReach, i + arr[i]);
    if (maxReach >= n - 1)
    {
      return jump + 1;
    }
    if (i == currReach)
    {
      if (i == maxReach)
      {
        return -1;
      }
      else
      {
        currReach = maxReach;
        jump++;
      }
    }
  }
  return -1;
}

bool canJump(vector<int> &nums)
{
  // your code goes here
  int maxIndex = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (i > maxIndex)
    {
      return false;
    }
    maxIndex = max(maxIndex, i + nums[i]);
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    v.push_back(data);
  }
  cout << canJump(v) << endl;
}