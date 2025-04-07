#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int left = 0;
  int right = m - 1;
  while (left < n && right >= 0)
  {
    if (nums1[right] >= nums2[left])
    {
      int temp = nums1[right];
      nums1[right] = nums2[left];
      nums2[left] = temp;
      right--;
      left++;
    }
    else
    {
      break;
    }
  }

  sort(nums1.begin() + 0, nums1.begin() + m);
  sort(nums2.begin(), nums2.end());
  for (int i = m; i < m + n; i++)
    nums1.push_back(nums2[i - m]);
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> v1;
  vector<int> v2;
  for (int i = 0; i < m; i++)
  {
    int val;
    cin >> val;
    v1.push_back(val);
  }
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v2.push_back(val);
  }

  merge(v1, m, v2, n);
  for (auto a1 : v1)
  {
    cout << a1 << " ";
  }
  cout << endl;
}