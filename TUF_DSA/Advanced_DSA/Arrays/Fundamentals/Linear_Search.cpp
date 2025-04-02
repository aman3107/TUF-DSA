#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &nums, int target)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums.at(i) == target)
    {
      return i;
    }
  }
  return -1;

  // TC = O(n)
  // SC = O(1)
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
  int target;
  cin >> target;
  cout << linearSearch(arr, target) << endl;
}