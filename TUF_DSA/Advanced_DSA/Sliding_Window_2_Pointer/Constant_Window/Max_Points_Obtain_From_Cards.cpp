#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardScore, int k)
{
  // your code goes here
  int n = cardScore.size();
  int lSum = 0;
  int rSum = 0;
  int maxSum = 0;
  for (int i = 0; i < k; i++)
  {
    lSum += cardScore[i];
  }
  maxSum = lSum;
  int rightIndex = n - 1;
  for (int i = k - 1; i >= 0; i--)
  {
    lSum = lSum - cardScore[i];
    rSum = rSum + cardScore[rightIndex];
    maxSum = max(maxSum, lSum + rSum);
    rightIndex--;
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

  cout << maxScore(arr, k) << endl;
}