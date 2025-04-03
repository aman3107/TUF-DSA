#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n1 && j < n2)
  {
    if (nums1[i] < nums2[j])
    {
      i++;
    }
    else if (nums2[j] < nums1[i])
    {
      j++;
    }
    else
    {
      ans.push_back(nums1[i]);
      i++;
      j++;
    }
  }
  return ans;

  // TC = O(n)
  // SC = O(1)
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
  vector<int> ans = intersectionArray(v1, v2);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}