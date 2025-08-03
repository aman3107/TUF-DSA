#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &nums, int target)
{
  // your code goes here
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == target)
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
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  int target;
  cin >> target;
  cout << linearSearch(arr, target);
}