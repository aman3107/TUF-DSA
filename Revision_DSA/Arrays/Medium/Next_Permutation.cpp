#include <bits/stdc++.h>
using namespace std;

/*
✅ Problem: Next Permutation
Given a list of numbers, rearrange them into the next lexicographically greater permutation.
If such arrangement is not possible (i.e., array is in descending order), rearrange it to the lowest possible order (sorted in ascending).

🧠 Intuition
We want to transform the current permutation into the next one in lexicographic order with minimum change.
🔍 Step-by-Step Explanation
Given:
vector<int> nums = {1, 2, 3};
Step 1: Find the first decreasing element from the right
Find the index ind such that:
nums[ind] < nums[ind + 1]
Scan from right to left. This is your pivot — the point where the next permutation change should begin.
Example:
For [1, 3, 5, 4, 2],
ind = 1 (nums[1] = 3, nums[2] = 5)

Step 2: If such index is found, find just greater element from the right
Find the smallest number greater than nums[ind], to the right of ind.
Then swap them.
Example:
Find > 3 in [5, 4, 2] → smallest is 4. Swap 3 and 4.
Array becomes: [1, 4, 5, 3, 2]

Step 3: Reverse the elements from ind+1 to end
Why? To get the next smallest permutation after the swap.

From [1, 4, 5, 3, 2]
→ reverse [5, 3, 2] to get [1, 4, 2, 3, 5] — the next permutation.

Edge Case:
If no such ind is found, reverse the entire array — it's already the last permutation.

Example:
Input: [5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5]

Time & Space Complexity
Time: O(n) – a few linear scans

Space: O(1) – in-place
*/

void nextPermutation(vector<int> &nums)
{
  // Your code goes here
  int n = nums.size();
  int ind = -1;
  // First find the break Point
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      ind = i;
      break;
    }
  }

  // Second find the second greatest
  if (ind != -1)
  {
    for (int i = n - 1; i >= ind; i--)
    {
      if (nums[i] > nums[ind])
      {
        swap(nums[i], nums[ind]);
        break;
      }
    }
    reverse(nums.begin() + (ind + 1), nums.end());
  }
  else
  {
    reverse(nums.begin(), nums.end());
  }
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
  nextPermutation(arr);
  for (auto &it : arr)
  {
    cout << it << " ";
  }
  cout << endl;
}