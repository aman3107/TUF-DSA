#include <bits/stdc++.h>
using namespace std;

vector<int> suffixSumArray(vector<int> &arr)
{
  int n = arr.size();
  vector<int> suffixSum(n);
  suffixSum[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    suffixSum[i] = (max(suffixSum[i + 1], arr[i]));
  }
  return suffixSum;
}

vector<int> prefixSumArray(vector<int> &arr)
{
  int n = arr.size();
  vector<int> prefixSum;
  prefixSum.push_back(arr[0]);
  for (int i = 1; i < n; i++)
  {
    prefixSum.push_back(max(prefixSum.back(), arr[i]));
  }
  return prefixSum;
}

int trappingRainWater(vector<int> &arr)
{
  int n = arr.size();
  int leftMax = 0;
  int rightMax = 0;
  int l = 0;
  int r = n - 1;
  int total = 0;
  while (l < r)
  {
    if (arr[l] <= arr[r])
    {
      if (leftMax > arr[l])
      {
        total += leftMax - arr[l];
      }
      else
      {
        leftMax = arr[l];
      }
      l++;
    }
    else
    {
      if (rightMax > arr[r])
      {
        total += rightMax - arr[r];
      }
      else
      {
        rightMax = arr[r];
      }
      r--;
    }
  }
  return total;
}

int trappingRainWaterBrute(vector<int> &arr)
{
  // vector<int> leftMax = prefixSumArray(arr);
  vector<int> rightMax = suffixSumArray(arr);
  int total = 0;
  int n = arr.size();

  int leftMax = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    leftMax = max(leftMax, arr[i]);
    if (arr[i] < leftMax && arr[i] < rightMax[i])
    {
      total += min(leftMax, rightMax[i]) - arr[i];
    }
  }
  return total;
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

  cout << trappingRainWater(arr) << endl;

  // vector<int> ans = suffixSumArray(arr);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << ans[i] << " ";
  // }
  // cout << endl;
}