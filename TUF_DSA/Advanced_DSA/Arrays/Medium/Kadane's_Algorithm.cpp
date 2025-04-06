#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
  long long maxSum = LLONG_MIN;
  long long sum = 0;
  int startIndex = -1;
  int endIndex = -1;
  for (int i = 0; i < nums.size(); i++)
  {
    if (sum == 0)
    {
      startIndex = i;
    }
    sum = sum + nums[i];
    if (sum > maxSum)
    {
      endIndex = i;
      maxSum = sum;
    }
    if (sum < 0)
    {
      sum = 0;
    }
  }

  cout << startIndex << " " << endIndex << endl;
  return maxSum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }
  cout << maxSubArray(v) << endl;
}