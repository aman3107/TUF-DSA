#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int x)
{
  int low = 0;
  int high = nums.size() - 1;
  int ans = nums.size();
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int LIS(vector<int> &nums)
{
  // Creating a temp array
  vector<int> ans;
  int len = 1;
  ans.push_back(nums[0]);
  for (int i = 1; i < nums.size(); i++)
  {
    // Check if the current value is lesser than or equal to last element in temp array. Then we will get the index of that element using lower bound to put that element into the temp array
    if (nums[i] <= ans.back())
    {
      int ind = lowerBound(ans, nums[i]);
      ans[ind] = nums[i];
    }
    // If current element is greater than put that element into the temp array
    else
    {
      len++;
      ans.push_back(nums[i]);
    }
  }
  return len;
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
  cout << LIS(arr) << endl;
}
