#include <bits/stdc++.h>
using namespace std;

/*
🧠 Intuition:
This is an extension of the two-sum problem, now looking for three numbers that sum up to 0.
The key idea is:
Fix the first number (nums[i])
Use the two-pointer technique on the rest of the array to find the remaining two numbers.

🧭 Approach:
Step-by-step:
Sort the array
This helps handle duplicates and enables the two-pointer approach.
Iterate through the array with index i:
Skip duplicates using: if (i > 0 && nums[i] == nums[i-1]) continue;
Set two pointers
l = i + 1 (left)
r = n - 1 (right)
While l < r:
Compute sum = nums[i] + nums[l] + nums[r]
If sum == 0: valid triplet!
Push {nums[i], nums[l], nums[r]} to the answer.
Move both pointers and skip duplicates
If sum < 0: increase l to get a larger sum
If sum > 0: decrease r to get a smaller sum
Return all found triplets

Time: O(n^2)
Sorting: O(n log n)
Outer loop + two-pointer scan: O(n^2)
Space: O(1) extra (not counting output
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n - 2; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int l = i + 1;
    int r = n - 1;
    while (l < r)
    {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum == 0)
      {
        ans.push_back({nums[i], nums[l], nums[r]});
        l++;
        r--;
        while (l < r && nums[r] == nums[r + 1])
        {
          r--;
        }
        while (l < r && nums[l] == nums[l - 1])
        {
          l++;
        }
      }
      else if (sum > 0)
      {
        r--;
      }
      else
      {
        l++;
      }
    }
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
  vector<vector<int>> ans = threeSum(arr);
  for (auto &it : ans)
  {
    for (auto &it1 : it)
    {
      cout << it1 << " ";
    }
  }
  cout << endl;
}