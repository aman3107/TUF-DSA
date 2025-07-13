#include <bits/stdc++.h>
using namespace std;
/*
Understanding
A bitonic sequence is one that first strictly increases and then strictly decreases. Finding the longest bitonic sequence involves combining two well-known concepts:
Longest Increasing Subsequence (LIS): the longest subsequence where elements are strictly increasing.
Longest Decreasing Subsequence (LDS): the longest subsequence where elements are strictly decreasing.

The goal is to identify a peak element where the sequence switches from increasing to decreasing.
1. Computing LIS from the Left
For each element in the array, compute the length of the LIS ending at that element. This captures how long an increasing sequence can be formed up to that point. It builds the foundation of the "increasing" part of the bitonic sequence.
2. Computing LDS from the Right
Similarly, for each element, compute the length of the LDS starting at that element by traversing from the end towards the beginning. This captures how long a decreasing sequence can be formed starting from that element, forming the "decreasing" part of the bitonic sequence.

3. For each potential peak (where both LIS[i] > 1 and LDS[i] > 1), calculate the mountain length as LIS[i] + LDS[i] - 1.

4. Combining LIS and LDS to Get the Bitonic Length
The length of the longest bitonic subsequence with the current element as the peak is the sum of the LIS ending at it and LDS starting at it, minus 1 (because the peak element is counted twice). By iterating over all elements and computing this combined length, the global maximum represents the length of the longest bitonic sequence.
Approach:

Find the length of the Longest Increasing Subsequence (LIS) ending at each element by checking all previous elements.
Find the length of the Longest Decreasing Subsequence (LDS) starting at each element by checking all subsequent elements.
Combine LIS and LDS lengths at each element to get the length of the bitonic subsequence passing through that element.
Track and return the maximum combined length found, subtracting 1 to avoid double-counting the peak element.*/

/*
dp1[i] stores the length of the Longest Increasing Subsequence (LIS) ending at index i.
dp2[i] stores the length of the Longest Decreasing Subsequence (LDS) starting from index i.
The bitonic length at index i is dp1[i] + dp2[i] - 1.
*/

void forward(vector<int> &arr, vector<int> &dp)
{
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
      {
        dp[i] = 1 + dp[j];
      }
    }
  }
}

void backward(vector<int> &arr, vector<int> &dp)
{
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
      {
        dp[i] = 1 + dp[j];
      }
    }
  }
}

int LongestBitonicSequence(vector<int> arr)
{
  int n = arr.size();
  vector<int> dp1(n, 1);
  vector<int> dp2(n, 1);
  forward(arr, dp1);
  backward(arr, dp2);

  int maxi = 1;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, (dp1[i] + dp2[i]) - 1);
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
  cout << LongestBitonicSequence(arr) << endl;
}