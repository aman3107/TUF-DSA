#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
  int n = arr.size();
  stack<int> st;
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty())
    {
      if (st.top() > arr[i])
      {
        break;
      }
      st.pop();
    }
    st.push(arr[i]);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty())
    {
      if (st.top() > arr[i])
      {
        ans[i] = st.top();
        break;
      }
      st.pop();
    }
    if (st.empty())
    {
      ans[i] = -1;
    }
    st.push(arr[i]);
  }
  return ans;
}

vector<int> nextGreaterElementsBrute(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int val = -1;
    for (int j = 0; j < n; j++)
    {
      int ind = (i + j) % n;
      if (arr[ind] > arr[i])
      {
        val = arr[ind];
        break;
      }
    }
    ans.push_back(val);
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
  vector<int> ans = nextGreaterElements(arr);
  for (int it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}