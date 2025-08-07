#include <bits/stdc++.h>
using namespace std;

/*
🧠 Intuition:
This is an extension of Two Sum and Three Sum problems.
Key idea:
Fix the first two elements (i and j)
Use the two-pointer technique to find the remaining two elements (l and r)

🧭 Approach:
Step-by-step:
Sort the array
Sorting helps skip duplicates and use two-pointers efficiently.
Loop 1 (i) from 0 to n-4:
Skip duplicates: if (i > 0 && nums[i] == nums[i-1]) continue
Loop 2 (j) from i+1 to n-3:
Skip duplicates: if (j > i+1 && nums[j] == nums[j-1]) continue
Two Pointers (l, r) from j+1 and n-1
While l < r, calculate the sum:
sum = nums[i] + nums[j] + nums[l] + nums[r];
If sum == target: valid quadruplet found:
Add to answer
Move both pointers and skip duplicates
If sum < target: move l++ (increase sum)
If sum > target: move r-- (decrease sum)
✅ Duplicates Handling:
Avoid repeated values for i, j, l, and r using:
if (i > 0 && nums[i] == nums[i - 1]) continue;
if (j > i + 1 && nums[j] == nums[j - 1]) continue;
while (l < r && nums[l] == nums[l - 1]) l++;
while (l < r && nums[r] == nums[r + 1]) r--;

⏱️ Time and Space Complexity:
Time: O(n^3)
Three nested loops and a two-pointer search
Space: O(1) (ignoring output)


*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n - 3; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n - 2; j++)
    {
      if (j > i + 1 && nums[j] == nums[j - 1])
      {
        continue;
      }
      int l = j + 1;
      int r = n - 1;
      while (l < r)
      {
        int sum = nums[i] + nums[j] + nums[l] + nums[r];
        if (sum == target)
        {
          ans.push_back({nums[i], nums[j], nums[l], nums[r]});
          l++;
          r--;
          while (l < r && nums[l] == nums[l - 1])
            l++;
          while (l < r && nums[r] == nums[r + 1])
            r--;
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
  int target;
  cin >> target;
  vector<vector<int>> ans = fourSum(arr, target);
  for (auto &it : ans)
  {
    for (auto &it1 : it)
    {
      cout << it1 << " ";
    }
  }
  cout << endl;
  return 0;
}