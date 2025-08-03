#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
  int n = nums.size();
  int sum = (n * (n + 1)) / 2;
  for (int i = 0; i < n; i++)
  {
    sum = sum - nums[i];
  }
  return sum;
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
  cout << missingNumber(arr);
}