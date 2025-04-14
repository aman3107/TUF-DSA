#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = INT_MAX;
  int ind = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[low] <= arr[high])
    {
      if (arr[low] < ans)
      {
        ind = low;
        ans = arr[low];
      }
      break;
    }
    if (arr[low] <= arr[mid])
    {
      if (arr[low] < ans)
      {
        ind = low;
        ans = arr[low];
      }
      low = mid + 1;
    }
    else
    {

      if (arr[mid] < ans)
      {
        ind = mid;
        ans = arr[mid];
      }
      high = mid - 1;
    }
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
  cout << findKRotation(v) << endl;
}