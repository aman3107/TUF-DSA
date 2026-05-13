#include <bits/stdc++.h>
using namespace std;

long long computeHour(vector<int> &nums, int div)
{
  long long int totalH = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    totalH += ceil((double)nums[i] / (double)div);
  }
  return totalH;
}

int minimumRateToEatBananas(vector<int> nums, int h)
{
  int low = 1;
  int high = *max_element(nums.begin(), nums.end());
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    long long midH = computeHour(nums, mid);
    if (midH <= h)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}

int computeSum(vector<int> &nums, int div)
{
  int sum = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    sum += ceil((double)nums[i] / div);
  }
  return sum;
}

int smallestDivisor(vector<int> &nums, int limit)
{
  int low = 1;
  int high = *max_element(nums.begin(), nums.end());
  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int sum = computeSum(nums, mid);
    if (sum <= limit)
    {
      ans = min(mid, ans);
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int helper(int mid, int n, int m)
{
  long long int base = mid;
  long long int ans = 1;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      ans = ans * base;
      if (ans > m)
        return 2;
      n--;
    }
    else
    {
      base = base * base;
      n = n / 2;
      if (base > m)
        return 2;
    }
  }
  if (ans == m)
    return 1;
  return 0;
}

int NthRoot(int N, int M)
{
  int low = 1;
  int high = M;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int midN = helper(mid, N, M);
    if (midN == 1)
      return mid;
    else if (midN == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int floorSqrt(int n)
{
  int low = 1;
  int high = n;
  int sqrt = 0;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    long long prod = 1LL * mid * mid;
    if (prod <= n)
    {
      sqrt = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return sqrt;
}

int main()
{
  int n;
  cin >> n;
  cout << floorSqrt(n);
}