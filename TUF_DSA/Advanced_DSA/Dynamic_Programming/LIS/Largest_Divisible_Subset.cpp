#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> nums)
{
  int n = nums.size();
  // Sorting the array
  sort(nums.begin(), nums.end());
  // DP Array
  vector<int> dp(n, 1);
  // Array to keep record of parent
  vector<int> hash(n, 0);
  // Store the maxLength of LIS
  int maxi = 1;
  // To store the last element index in the LIS
  int lastIndex = 0;
  for (int i = 0; i < n; i++)
  {
    // Assign the parent itself
    hash[i] = i;
    for (int prev = 0; prev < i; prev++)
    {
      // If the element at index i can be included in the LIS ending at index prev
      if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
      {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
    // If a longer LIS is found, update the values
    if (dp[i] > maxi)
    {
      maxi = dp[i];
      lastIndex = i;
    }
  }

  // BackTracking
  vector<int> ans;
  ans.push_back(nums[lastIndex]);
  // Until we reach an index which is its own parent
  while (hash[lastIndex] != lastIndex)
  {
    lastIndex = hash[lastIndex];
    // Add the element at current index
    ans.push_back(nums[lastIndex]);
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
  vector<int> ans = largestDivisibleSubset(arr);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}
