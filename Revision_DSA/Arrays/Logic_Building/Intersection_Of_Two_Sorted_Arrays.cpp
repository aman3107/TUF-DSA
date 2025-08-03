#include <bits/stdc++.h>
using namespace std;

/*
 Intuition:
The goal is to find the intersection of two sorted arrays — i.e., the elements that are common to both arrays.
Since both arrays are sorted, we can efficiently find common elements using the two-pointer technique, which allows us to scan both arrays in a single pass.

🧠 Approach:
Initialize two pointers:
s1 for the first array (nums1)
s2 for the second array (nums2)
Use a while loop to iterate while both pointers are within the bounds of their respective arrays.
Inside the loop:
If both elements are equal (nums1[s1] == nums2[s2]):
Add the element to the ans vector (result).
Increment both pointers to move to the next elements.
If nums1[s1] < nums2[s2]:
The current element in nums1 is smaller, so move s1 forward.
Else:
The current element in nums2 is smaller, so move s2 forward.
When one of the arrays is fully traversed, stop.
Return the ans vector which contains all the common elements.

Time Complexity: O(n + m)
Where n = size of nums1, m = size of nums2.
Space Complexity: O(1) extra (excluding result array)
In-place traversal using only two pointers.
*/

vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
  int e1 = nums1.size();
  int e2 = nums2.size();
  int s1 = 0;
  int s2 = 0;
  vector<int> ans;
  while (s1 < e1 && s2 < e2)
  {
    if (nums1[s1] == nums2[s2])
    {
      ans.push_back(nums1[s1]);
      s1++;
      s2++;
    }

    else if (nums1[s1] < nums2[s2])
    {
      s1++;
    }
    else
    {
      s2++;
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
  int m;
  cin >> m;
  vector<int> arr1;
  for (int i = 0; i < m; i++)
  {
    int data;
    cin >> data;
    arr1.push_back(data);
  }
  vector<int> ans = intersectionArray(arr, arr1);

  for (auto &it : ans)
  {
    cout << it << " ";
  }
}