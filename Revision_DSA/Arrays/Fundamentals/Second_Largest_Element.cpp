#include <bits/stdc++.h>
using namespace std;

/*
🔍 Intuition:
The problem asks us to find the second largest element in an array.
That is, the number that is less than the largest but greater than all others.
To solve this efficiently, we only need one pass through the array while keeping track of two variables:
maxi: the largest element so far
maxi2: the second largest element so far

🧠 Approach:
Initialize two variables:
maxi = INT_MIN → to store the largest element
maxi2 = INT_MIN → to store the second largest element
Traverse the array once using a loop:
If the current element nums[i] is greater than maxi:
Update maxi2 = maxi (the old max becomes second largest)
Update maxi = nums[i]
Else if the current element is less than maxi but greater than maxi2:
Update maxi2 = nums[i]
After the loop ends:
If no second largest exists (i.e., all elements are equal), then maxi2 will still be INT_MIN.
In that case, return -1 as a signal that no second largest element exists.

✅ Time and Space Complexity:
Time Complexity: O(n) – Single pass through the array.

Space Complexity: O(1) – Constant space used.
*/

int secondLargestElement(vector<int> &nums)
{
  // your code goes here

  int maxi = INT_MIN;
  int maxi2 = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > maxi)
    {
      maxi2 = maxi;
      maxi = nums[i];
    }
    else if (nums[i] > maxi2 && nums[i] < maxi)
    {
      maxi2 = nums[i];
    }
  }
  return maxi2 == INT_MIN ? -1 : maxi2;
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
  cout << secondLargestElement(arr);
}