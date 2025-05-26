#include <bits/stdc++.h>
using namespace std;

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

vector<int> nextGreaterElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && arr[st.top()] <= arr[i])
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

vector<int> previousGreaterElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] < arr[i])
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

long long sumSubMin(vector<int> &arr)
{
  vector<int> nse = nextSmallerElement(arr);
  vector<int> pse = previousSmallerElement(arr);
  int n = arr.size();
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    int left = i - pse[i];
    int right = nse[i] - i;
    long long freq = (right * left * 1ll);
    long long val = (freq * arr[i] * 1ll);
    sum = (sum + val);
  }
  return sum;
}
long long sumSubMax(vector<int> &arr)
{
  vector<int> nge = nextGreaterElement(arr);
  vector<int> pge = previousGreaterElement(arr);
  long long sum = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int left = i - pge[i];
    int right = nge[i] - i;
    long long freq = (left * right * 1ll);
    long long val = (freq * arr[i] * 1ll);
    sum = (sum + val);
  }
  return sum;
}

long long subArrayRanges(vector<int> &nums)
{
  return sumSubMax(nums) - sumSubMin(nums);
}

long long subArrayRangesBrute(vector<int> &nums)
{
  int n = nums.size();
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    int maxi = nums[i];
    int mini = nums[i];
    for (int j = i; j < n; j++)
    {
      maxi = max(maxi, nums[j]);
      mini = min(mini, nums[j]);
      sum += (maxi - mini);
    }
  }
  return sum;
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
  cout << subArrayRanges(arr) << endl;
}