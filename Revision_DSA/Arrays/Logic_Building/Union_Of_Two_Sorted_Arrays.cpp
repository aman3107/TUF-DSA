#include <bits/stdc++.h>
using namespace std;

/*
Use two pointers s1 and s2 to iterate through nums1 and nums2 respectively.
Compare current elements:
If nums1[s1] <= nums2[s2]: push nums1[s1], move s1.
Else: push nums2[s2], move s2.
To avoid duplicates, only add to the result if either:
ans is empty, or
ans.back() (last inserted element) is not equal to the current one
After the main loop, append remaining elements from both arrays (if any), again skipping duplicates.
Return the result ans.

Time Complexity: O(n + m)
where n = size of nums1, m = size of nums2.
Space Complexity: O(n + m) in the worst case (if all elements are unique and added to the result).


*/

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
  int e1 = nums1.size();
  int e2 = nums2.size();
  int s1 = 0;
  int s2 = 0;
  vector<int> ans;
  while (s1 < e1 && s2 < e2)
  {
    if (nums1[s1] <= nums2[s2])
    {
      if (ans.size() == 0 || ans.back() != nums1[s1])
        ans.push_back(nums1[s1]);
      s1++;
    }
    else
    {
      if (ans.size() == 0 || ans.back() != nums2[s2])
        ans.push_back(nums2[s2]);
      s2++;
    }
  }
  while (s1 < e1)
  {
    if (ans.size() == 0 || ans.back() != nums1[s1])
      ans.push_back(nums1[s1]);
    s1++;
  }

  while (s2 < e2)
  {
    if (ans.size() == 0 || ans.back() != nums2[s2])
      ans.push_back(nums2[s2]);
    s2++;
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
  vector<int> ans = unionArray(arr, arr1);

  for (auto &it : ans)
  {
    cout << it << " ";
  }
}