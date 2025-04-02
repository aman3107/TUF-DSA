#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &nums)
{
  int maxElement = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums.at(i) > maxElement)
    {
      maxElement = nums.at(i);
    }
  }
  return maxElement;
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
  cout << largestElement(arr) << endl;
}