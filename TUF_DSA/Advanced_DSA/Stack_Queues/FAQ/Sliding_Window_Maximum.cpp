#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
  deque<int> dq;
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (!dq.empty() && dq.front() <= (i - k))
    {
      dq.pop_front();
    }
    while (!dq.empty() && arr[dq.back()] <= arr[i])
    {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= (k - 1))
    {
      ans.push_back(arr[dq.front()]);
    }
  }
  return ans;
}

vector<int> maxSlidingWindowBrute(vector<int> &arr, int k)
{
  vector<int> ans;
  int n = arr.size();
  for (int i = 0; i <= n - k; i++)
  {
    int maxi = arr[i];
    for (int j = i + 1; j < k + i; j++)
    {
      maxi = max(maxi, arr[j]);
    }
    ans.push_back(maxi);
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
  int k;
  cin >> k;
  vector<int> ans = maxSlidingWindow(arr, k);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}