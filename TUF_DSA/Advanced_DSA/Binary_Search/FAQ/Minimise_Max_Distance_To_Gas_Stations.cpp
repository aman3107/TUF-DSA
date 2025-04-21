#include <bits/stdc++.h>
using namespace std;

int countGasStations(long double dist, vector<int> &arr)
{
  int cnt = 0;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int numberInBetween = ((arr[i + 1] - arr[i]) / dist);
    if (((arr[i + 1] - arr[i]) / dist) == numberInBetween * dist)
    {
      numberInBetween--;
    }
    cnt += numberInBetween;
  }
  return cnt;
}

long double minimiseMaxDistanceOptimal(vector<int> &arr, int k)
{
  int n = arr.size();
  long double low = 0;
  long double high = 0;
  for (int i = 0; i < n - 1; i++)
  {
    high = max(high, (long double)(arr[i + 1] - arr[i]));
  }

  long double diff = 1e-6;

  while (high - low > diff)
  {
    long double mid = (low + high) / (2.0);
    int cnt = countGasStations(mid, arr);
    if (cnt > k)
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
  }
  return high;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  for (int gasStations = 1; gasStations <= k; gasStations++)
  {
    long double maxVal = -1;
    int maxIndex = -1;
    for (int i = 0; i < n - 1; i++)
    {
      long double diff = (arr[i + 1] - arr[i]);
      long double sectionLength = diff / (long double)(howMany[i] + 1);
      if (maxVal < sectionLength)
      {
        maxVal = sectionLength;
        maxIndex = i;
      }
    }
    howMany[maxIndex]++;
  }

  long double ans = -1;
  for (int i = 0; i < n - 1; i++)
  {
    long double diff = arr[i + 1] - arr[i];
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    ans = max(ans, sectionLength);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    nums.push_back(val);
  }
  int k;
  cin >> k;
  cout << minimiseMaxDistance(nums, k) << endl;
}