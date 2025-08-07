#include <bits/stdc++.h>
using namespace std;

/*
🔍 Intuition:
A leader in an array is an element that is greater than all the elements to its right.
For example, in [16, 17, 4, 3, 5, 2], the leaders are:
17 (greater than 4, 3, 5, 2),
5 (greater than 2),
2 (rightmost is always a leader).
We need to scan the array from right to left, keeping track of the maximum value seen so far. If the current element is greater than the max, it's a leader.

🧠 Approach:
Initialize a result vector ans and store the last element (always a leader).
Initialize maxi as the last element of the array.
Loop from the second last to the first element:
If the current element is greater than maxi, it is a leader:
Update maxi
Add it to the ans vector.
Reverse the ans vector because leaders are collected in reverse order.
Return ans.

Time & Space Complexity:
Time Complexity: O(n)
Single pass from end to start.

Space Complexity: O(k)
Where k = number of leaders stored in ans.
*/

vector<int> leaders(vector<int> &nums)
{
  vector<int> ans;
  int n = nums.size();
  ans.push_back(nums[n - 1]);
  int maxi = nums[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] > maxi)
    {
      maxi = nums[i];
      ans.push_back(nums[i]);
    }
  }
  reverse(ans.begin(), ans.end());
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
  vector<int> ans = leaders(arr);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}