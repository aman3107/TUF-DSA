#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int countOnes = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      count += 1;
      if (count > countOnes)
      {
        countOnes = count;
      }
    }
    else
    {
      count = 0;
    }
  }
  return countOnes;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  cout << findMaxConsecutiveOnes(arr) << endl;
}