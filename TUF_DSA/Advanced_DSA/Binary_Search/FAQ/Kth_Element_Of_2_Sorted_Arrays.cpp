#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
  int n1 = a.size();
  int n2 = b.size();
  if (n1 > n2)
  {
    return kthElement(b, a, k);
  }
  int left = k;
  int low = max(0, k - n2);
  int high = min(k, n1);
  while (low <= high)
  {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;
    int l1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
    int r1 = mid1 < n1 ? a[mid1] : INT_MAX;
    int l2 = mid2 > 0 ? b[mid2 - 1] : INT_MIN;
    int r2 = mid2 < n2 ? b[mid2] : INT_MAX;
    if (l1 <= r2 && l2 < +r1)
    {
      return max(l1, l2);
    }
    else if (l1 > r2)
    {
      high = mid1 - 1;
    }
    else
    {
      low = mid1 + 1;
    }
  }
  return 0;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> arr1;
  vector<int> arr2;
  for (int i = 0; i < n1; i++)
  {
    int val;
    cin >> val;
    arr1.push_back(val);
  }
  for (int i = 0; i < n2; i++)
  {
    int val;
    cin >> val;
    arr2.push_back(val);
  }
  int k;
  cin >> k;
  cout << kthElement(arr1, arr2, k) << endl;
}