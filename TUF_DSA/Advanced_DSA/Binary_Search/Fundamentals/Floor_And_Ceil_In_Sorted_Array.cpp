#include <bits/stdc++.h>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int floor = -1;
  int ceil = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] > x)
    {
      ceil = nums[mid];
      high = mid - 1;
    }
    else if (nums[mid] < x)
    {
      floor = nums[mid];
      low = mid + 1;
    }
    else
    {
      floor = nums[mid];
      ceil = nums[mid];
      return {floor, ceil};
    }
  }
  return {floor, ceil};
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
  int x;
  cin >> x;
  vector<int> ans = getFloorAndCeil(v, x);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}