#include <bits/stdc++.h>
using namespace std;

/*
🔍 Intuition:
The goal of this problem is simple:
We are given an array of integers, and we need to find the largest (maximum) element in it.

To do that, we can just scan every element one by one and keep track of the maximum seen so far.
This is a classic use of linear traversal, where we compare each number to the current known maximum and update the maximum if we find a bigger number.

🧠 Approach:
Initialize a variable maxi with the smallest possible integer (INT_MIN) to ensure any number in the array will be larger initially.

Iterate through the array using a loop.

For each element num in the array:

Compare it with maxi.

If num > maxi, update maxi = num.

After the loop ends, maxi will hold the largest element in the array.

Return maxi.

✅ Time and Space Complexity:
Time Complexity: O(n)
We traverse the entire array once, where n is the number of elements.

Space Complexity: O(1)
We use only a constant amount of extra space (maxi).
*/

int largestElement(vector<int> &nums)
{
  int maxi = INT_MIN;
  for (auto &num : nums)
  {
    maxi = max(maxi, num);
  }
  return maxi;
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
  cout << largestElement(arr);
}