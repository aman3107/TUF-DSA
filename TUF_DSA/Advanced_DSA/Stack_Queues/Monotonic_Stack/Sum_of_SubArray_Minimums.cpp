#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] > arr[i])
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

vector<int> nextSmallerElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && arr[st.top()] >= arr[i])
    {
      st.pop();
    }
    if (st.empty())
    {
      ans[i] = n;
    }
    else
    {
      ans[i] = st.top();
    }
    st.push(i);
  }
  return ans;
}

int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  int mod = 1e9 + 7;
  vector<int> nse = nextSmallerElement(arr);
  vector<int> pse = previousSmallerElement(arr);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int right = nse[i] - i;
    int left = i - pse[i];
    long long freq = (left * right * 1ll);
    int val = (freq * arr[i] * 1ll) % mod;
    sum = (sum + val) % mod;
  }
  return sum;
}

int sumSubarrayMinsBrute(vector<int> &arr)
{
  int sum = 0;
  int n = arr.size();
  int mod = 1e9 + 7;
  for (int i = 0; i < n; i++)
  {
    int val = INT_MAX;
    for (int j = i; j < n; j++)
    {
      val = min(val, arr[j]);
      sum += val;
    }
  }
  return sum % mod;
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
  // vector<int> ans1 = nextSmallerElement(arr);
  // for (int i = 0; i < ans1.size(); i++)
  // {
  //   cout << ans1[i] << " ";
  // }
  // cout << endl;
  // vector<int> ans2 = previousSmallerElement(arr);
  // for (int i = 0; i < ans2.size(); i++)
  // {
  //   cout << ans2[i] << " ";
  // }
  // cout << endl;
  cout << sumSubarrayMins(arr) << endl;
}