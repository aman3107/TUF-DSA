#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> ump;
  stack<int> st;
  vector<int> ans;
  int n = nums2.size();
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty())
    {
      if (st.top() > nums2[i])
      {
        ump[nums2[i]] = st.top();
        break;
      }
      st.pop();
    }
    if (st.empty())
    {
      ump[nums2[i]] = -1;
    }
    st.push(nums2[i]);
  }

  int m = nums1.size();
  for (int i = 0; i < m; i++)
  {

    ans.push_back(ump[nums1[i]]);
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
  vector<int> ans = nextGreaterElement(arr, arr1);
  for (int it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}