#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSumHelper(vector<int> &nums, int goal)
{

  if (goal < 0)
  {
    return 0;
  }
  int l = 0;
  int r = 0;
  int count = 0;
  int sum = 0;
  int n = nums.size();
  while (r < n)
  {
    sum += nums[r];
    while (sum > goal)
    {
      sum -= nums[l];
      l++;
    }

    count += (r - l + 1);

    r++;
  }
  return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
  return numSubarraysWithSumHelper(nums, goal) - numSubarraysWithSumHelper(nums, goal - 1);
}

int numSubarraysWithSumBrute(vector<int> &nums, int goal)
{
  // your code goes here
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum == goal)
      {
        cnt++;
      }
    }
  }
  return cnt;
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
  int goal;
  cin >> goal;
  cout << numSubarraysWithSum(arr, goal) << endl;
}