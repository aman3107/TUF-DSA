#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int x)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int mid = low + (high - low) / 2;
  int ans = n;
  while (low <= high)
  {
    if (nums[mid] >= x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
    mid = low + (high - low) / 2;
  }
  return ans;
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
  int target;
  cin >> target;
  cout << lowerBound(v, target) << endl;
}