#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &nums)
{
  // your code goes here
  int maxElement = nums[0];
  int secondMax = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums.at(i) > maxElement)
    {
      secondMax = maxElement;
      maxElement = nums.at(i);
    }
    else if (nums.at(i) > secondMax && nums.at(i) != maxElement)
    {
      secondMax = nums.at(i);
    }
  }
  return secondMax == INT_MIN ? -1 : secondMax;
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
  cout << secondLargestElement(arr) << endl;
}