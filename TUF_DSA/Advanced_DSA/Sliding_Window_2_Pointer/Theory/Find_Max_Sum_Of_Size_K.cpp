#include <bits/stdc++.h>
using namespace std;

int kSum(vector<int> &arr, int k)
{
  int n = arr.size();
  int sum = 0;
  int maxSum = 0;
  for (int i = 0; i < k; i++)
  {
    sum += arr[i];
  }
  maxSum = sum;
  for (int i = k; i < n; i++)
  {
    sum += arr[i] - arr[i - k];
    maxSum = max(maxSum, sum);
  }
  return maxSum;
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

  cout << kSum(arr, k) << endl;
}