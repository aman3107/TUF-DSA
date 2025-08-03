#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
Since the array is sorted, all duplicates will be adjacent.

Use two pointers:

i → points to the last unique element.
j → scans the array for the next unique element.
When you find a new value at j:
Move i forward.
Overwrite nums[i] with nums[j].
After the loop, the first i+1 elements in nums are unique.

Time and Space Complexity:
Time Complexity: O(n)

Space Complexity: O(1) (in-place)

*/

int removeDuplicates(vector<int> &nums)
{
  int i = 0;
  for (int j = 1; j < nums.size(); j++)
  {
    if (nums[i] != nums[j])
    {
      i++;
      nums[i] = nums[j];
    }
  }
  return i + 1;
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
  cout << removeDuplicates(arr);
}