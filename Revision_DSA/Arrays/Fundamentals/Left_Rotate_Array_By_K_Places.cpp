#include <bits/stdc++.h>
using namespace std;

/*
 Use reversal to achieve this rotation in-place (no extra space) with three steps:

Reverse the first k elements
Reverse the remaining n-k elements
Reverse the entire array
This rearranges the parts into the correct rotated order.

Given:
nums = [1, 2, 3, 4, 5, 6, 7], k = 3
First reverse the first k elements:
[3, 2, 1, 4, 5, 6, 7]
Then reverse the remaining elements:
[3, 2, 1, 7, 6, 5, 4]
Finally, reverse the entire array:
[4, 5, 6, 7, 1, 2, 3]

✅ Time and Space Complexity:
Time Complexity: O(n) – Each reversal takes O(n) time total.

Space Complexity: O(1) – In-place with no extra space.
*/

void reverse(vector<int> &arr, int si, int ei)
{
  while (si <= ei)
  {
    int temp = arr[si];
    arr[si] = arr[ei];
    arr[ei] = temp;
    si++;
    ei--;
  }
}

void rotateArray(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
  reverse(nums, 0, n - 1);
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
  int k;
  cin >> k;
  rotateArray(arr, k);
}