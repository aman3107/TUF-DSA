#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> arr)
{
  stack<int> st;
  int n = arr.size();
  vector<int> ans(n);
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

vector<int> nextLargerElementBrute(vector<int> arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int val = -1;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        val = arr[j];
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
  vector<int> ans = nextLargerElement(arr);
  for (int it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}