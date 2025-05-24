#include <bits/stdc++.h>
using namespace std;

int numberOfOddSubarraysHelper(vector<int> &nums, int k)
{
  if (k < 0)
  {
    return 0;
  }
  int l = 0, r = 0;
  int n = nums.size();
  int sum = 0;
  int count = 0;
  while (r < n)
  {
    sum += (nums[r] % 2);
    while (sum > k)
    {
      sum -= (nums[l] % 2);
      l++;
    }
    count += (r - l + 1);
    r++;
  }
  return count;
}

int numberOfOddSubarrays(vector<int> &nums, int k)
{
  return numberOfOddSubarraysHelper(nums, k) - numberOfOddSubarraysHelper(nums, k - 1);
}

int numberOfOddSubarraysBrute(vector<int> &nums, int k)
{
  // your code goes here
  int n = nums.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int oddCount = 0;
    for (int j = i; j < n; j++)
    {
      if (nums[j] % 2)
      {
        oddCount++;
      }
      if (oddCount == k)
      {
        count++;
      }
    }
  }
  return count;
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
  int k;
  cin >> k;
  cout << numberOfOddSubarrays(arr, k) << endl;
}