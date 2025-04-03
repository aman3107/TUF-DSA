#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n1 && j < n2)
  {
    if (nums1[i] <= nums2[j])
    {
      if (ans.size() == 0 || ans.back() != nums1[i])
        ans.push_back(nums1[i]);
      i++;
    }
    else
    {
      if (ans.size() == 0 || ans.back() != nums2[j])
        ans.push_back(nums2[j]);
      j++;
    }
  }
  while (i < n1)
  {
    if (ans.back() != nums1[i])
      ans.push_back(nums1[i]);
    i++;
  }
  while (j < n2)
  {
    if (ans.back() != nums2[j])
      ans.push_back(nums2[j]);
    j++;
  }
  return ans;

  // TC  =  O(N)
  // SC  = O(1)
}

int main()
{
  int n, m;
  cin >> n;
  cin >> m;
  vector<int> v1;
  vector<int> v2;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v1.push_back(val);
  }

  for (int i = 0; i < m; i++)
  {
    int val;
    cin >> val;
    v2.push_back(val);
  }
  vector<int> ans = unionArray(v1, v2);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}