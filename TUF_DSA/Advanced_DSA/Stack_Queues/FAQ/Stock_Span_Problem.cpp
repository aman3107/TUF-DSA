#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreaterElement(vector<int> &arr, int n)
{
  stack<int> st;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[i] >= arr[st.top()])
    {
      st.pop();
    }
    if (st.empty())
    {
      ans[i] = -1;
    }
    else
    {
      ans[i] = st.top();
    }
    st.push(i);
  }
  return ans;
}

vector<int> stockSpan(vector<int> arr, int n)
{
  vector<int> pge = previousGreaterElement(arr, n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    ans[i] = i - pge[i];
  }
  return ans;
}

vector<int> stockSpanBrute(vector<int> &arr, int n)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j >= 0; j--)
    {
      if (arr[j] > arr[i])
      {
        break;
      }
      sum++;
    }
    ans.push_back(sum);
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
  vector<int> ans = stockSpanBrute(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}