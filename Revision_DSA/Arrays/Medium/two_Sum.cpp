#include <bits/stdc++.h>
using namespace std;

// When only yes and no
/*
Intuition:
You are given an array nums and a target.
You need to check if any two elements in the array add up to the target, and return true or false.
This version is slightly different from the previous one:
Instead of returning the indices, it only returns whether a valid pair exists.
Since we don't need the original indices, we can sort the array and use the two-pointer technique for an efficient solution.

🧠 Approach:
Sort the array.
Sorting is necessary to apply the two-pointer technique.
Initialize two pointers:
l → points to the beginning
r → points to the end
Iterate while l < r:
If nums[l] + nums[r] == target → return true
If the sum is greater than target → decrement r
If the sum is less than target → increment l
If loop ends without finding a pair → return false

Time and Space Complexity:
Time:
Sorting = O(n log n)
Two-pointer scan = O(n)
→ Overall: O(n log n)
Space: O(1) (in-place sort, no extra space)

*/
bool twoSum1(vector<int> &nums, int target)
{
  sort(nums.begin(), nums.end());
  int l = 0;
  int r = nums.size() - 1;
  while (l < r)
  {
    if (nums[l] + nums[r] == target)
    {
      return true;
    }
    else if (nums[l] + nums[r] > target)
    {
      r--;
    }
    else
    {
      l++;
    }
  }
  return false;
}

// When index needs to return
/*
Approach:
✅ Step-by-step:
Initialize a hash map mp to store:
key   = number seen so far
value = its index
Traverse the array using a for-loop.

For each element nums[i], calculate:
rem = target - nums[i]
Check if rem exists in the map:

If yes: return the pair of indices: {mp[rem], i}
If not: store nums[i] in the map with its index

Time: O(n) — one pass through the array
Space: O(n) — for storing elements in the hash map
*/
vector<int> twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++)
  {
    int rem = target - nums[i];
    if (mp.find(rem) != mp.end())
    {

      return {mp[rem], i};
    }
    mp[nums[i]] = i;
  }
  return {};
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
  vector<int> ans = twoSum(arr, target);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}