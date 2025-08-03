#include <bits/stdc++.h>
using namespace std;

/*
🧠 Approach:
Store the first element of the array in a temporary variable temp, since it will be lost during shifting.

Shift all elements one step to the left:

For each index i from 1 to n-1, set nums[i - 1] = nums[i].

After the loop, place the original first element (stored in temp) at the end of the array: nums[n - 1] = temp.

✅ Time and Space Complexity:
Time Complexity: O(n) – You’re moving each element once.

Space Complexity: O(1) – You use a single extra variable (temp).
*/

void rotate(vector<int> &nums)
{
  // code here
  int n = nums.size();
  int temp = nums[n - 1];
  for (int i = n - 1; i >= 1; i--)
  {
    nums[i] = nums[i - 1];
  }
  nums[0] = temp;
}

void rotateArrayByOne(vector<int> &nums)
{
  int temp = nums[0];
  int n = nums.size();
  for (int i = 1; i < n; i++)
  {
    nums[i - 1] = nums[i];
  }
  nums[n - 1] = temp;
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
  rotateArrayByOne(arr);
}