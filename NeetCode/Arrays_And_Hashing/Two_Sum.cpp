#include <bits/stdc++.h>
using namespace std;

/*
✅ Problem:
Given an array nums and a target sum, return the indices of the two numbers such that they add up to the target. You may assume that each input has exactly one solution, and you may not use the same element twice.

🔍 Intuition:
We want to find two numbers in the array whose sum equals the target.
If the array is sorted, we can apply a two-pointer technique:
One pointer at the beginning (smallest number)
One pointer at the end (largest number)
→ Move the pointers based on the sum compared to the target.
However, the original array isn't sorted, and we need to return original indices.
So, we:
Pair each number with its index.
Sort the array based on the values.
Apply the two-pointer technique.
Return the original indices of the pair.

🧠 Approach:
Step-by-step:
Store each number and its original index
→ Use a 2D vector temp where each entry is {nums[i], i}.
temp.push_back({nums[i], i});
Sort the temp array based on the number values.
Since you're not using a custom comparator, default sorting sorts by temp[i][0] (the number), which works here.
sort(temp.begin(), temp.end());
Initialize two pointers:

l = 0 (left)
r = nums.size() - 1 (right)
Iterate using two-pointer technique:
Compute the sum of values at l and r.
If the sum matches the target → return original indices.
If the sum is greater than the target → move r left.
If the sum is smaller → move l right.
Return the result:
Return the pair of original indices in increasing order using min() and max().

✅ Example:
Input:
nums = [2, 7, 11, 15], target = 9
Step-by-step:

temp = {{2,0}, {7,1}, {11,2}, {15,3}}

After sorting by value (already sorted):
temp = {{2,0}, {7,1}, {11,2}, {15,3}}

Two-pointer:

l = 0, r = 3: sum = 2+15 = 17 → move r

l = 0, r = 2: sum = 2+11 = 13 → move r

l = 0, r = 1: sum = 2+7 = 9 → found!

Return {0,1}

⏱️ Time & Space Complexity:
Time:

Creating temp array: O(n)
Sorting: O(n log n)
Two-pointer search: O(n)
→ Total: O(n log n)

Space:
Extra space for temp array: O(n)
✅ Why use min() and max() in the return?
To ensure the smaller index comes first, especially when the input requires a specific order.


*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<vector<int>> temp;
    for (int i = 0; i < nums.size(); i++)
    {
      temp.push_back({nums[i], i});
    }
    sort(temp.begin(), temp.end());
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
      int sum = temp[l][0] + temp[r][0];
      if (sum == target)
      {
        return {min(temp[l][1], temp[r][1]), max(temp[l][1], temp[r][1])};
      }
      else if (sum > target)
      {
        r--;
      }
      else
      {
        l++;
      }
    }
    return {};
  }
};

/*
 Intuition:
To find two elements in the array that add up to a given target, we can store previously seen numbers in a hash map so we can check in constant time whether the required complement exists.

This avoids the need for sorting or nested loops, resulting in a linear time solution.

🧠 Approach:
Use an unordered map (mp) to store {number → index}.
First pass:
Store all elements of the array in the map along with their indices.

for (int i = 0; i < book.size(); i++) {
    mp[book[i]] = i;
}
Second pass:

For each element book[i], compute the complement needed to reach the target:
int diff = target - book[i];
Check if this diff exists in the map and isn't the same index (to avoid using the same element twice):
if (mp.count(diff) && mp[diff] != i)
Return the indices when found.
If no valid pair is found, return {-1, -1}.
🔍 Example:
Input:
book = [3, 2, 4], target = 6
Map after first pass: {3:0, 2:1, 4:2}

Iteration:

i = 0 → target - 3 = 3 → not valid (mp[3] == i)

i = 1 → target - 2 = 4 → mp[4] = 2, and 2 ≠ 1 → match!

Return {1, 2}

⏱️ Time & Space Complexity:
Time: O(n)
Space: O(n)

This is faster than the sorting + two-pointer method, especially when order doesn't matter and we only need any one valid pair.
*/

string read(int n, vector<int> book, int target)
{
  // Write your code here.
  unordered_map<int, int> mp;
  for (int i = 0; i < book.size(); i++)
  {
    mp[book[i]] = i;
  }
  for (int i = 0; i < book.size(); i++)
  {
    int diff = target - book[i];
    if (mp.count(diff) && mp[diff] != i)
    {
      return "YES";
    }
  }
  return "NO";
}
