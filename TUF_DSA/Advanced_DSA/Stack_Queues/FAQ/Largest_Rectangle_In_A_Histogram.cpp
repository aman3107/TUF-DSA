#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  stack<int> st;
  vector<int> ans(n);
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

vector<int> previousSmallerElement(vector<int> &arr, int n)
{
  stack<int> st;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] >= arr[i])
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

int largestRectangleArea(vector<int> &heights)
{
  int n = heights.size();
  int maxi = 0;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && heights[st.top()] > heights[i])
    {
      int val = heights[st.top()];
      st.pop();
      int nse = i;
      int pse = !st.empty() ? st.top() : -1;
      int areaRectangle = val * (nse - pse - 1);
      maxi = max(maxi, areaRectangle);
    }
    st.push(i);
  }
  while (!st.empty())
  {
    int val = heights[st.top()];
    st.pop();
    int nse = n;
    int pse = !st.empty() ? st.top() : -1;
    int areaRectangle = val * (nse - pse - 1);
    maxi = max(maxi, areaRectangle);
  }
  return maxi;
}
int largestRectangleAreaBrute(vector<int> &heights)
{
  int n = heights.size();
  vector<int> nse = nextSmallerElement(heights, n);
  vector<int> pse = previousSmallerElement(heights, n);

  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    int val = heights[i] * (nse[i] - pse[i] - 1);
    maxi = max(maxi, val);
  }
  return maxi;
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

  cout << largestRectangleArea(arr) << endl;
}