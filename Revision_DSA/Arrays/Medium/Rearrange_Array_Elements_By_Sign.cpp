#include <bits/stdc++.h>
using namespace std;

/*
🔍 Intuition:
Given an array nums with an equal number of positive and negative integers, the task is to rearrange the elements such that:
Positive and negative numbers alternate, and
The first element is positive.

📌 Example:
Input: [3, 1, -2, -5, 2, -4]
Output: [3, -2, 1, -5, 2, -4]

🧠 Approach:
Initialize a result vector ans of size n (same as input) filled with 0.
Use two pointers:
pos starts at index 0 (for positive numbers).
neg starts at index 1 (for negative numbers).
Traverse the input array:
If the current number is positive, place it at index pos and increment pos by 2.
If it's negative, place it at index neg and increment neg by 2.
This ensures:
All positives go to even indices: 0, 2, 4, ...
All negatives go to odd indices: 1, 3, 5, ...
Return the result vector.

✅ Time & Space Complexity:
Time Complexity: O(n)
One pass through the array.

Space Complexity: O(n)
For the ans array.
*/

vector<int> rearrangeArray(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, 0);
  int pos = 0;
  int neg = 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= 0)
    {
      ans[pos] = nums[i];
      pos = pos + 2;
    }
    else
    {
      ans[neg] = nums[i];
      neg = neg + 2;
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
  vector<int> ans = rearrangeArray(arr);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}
