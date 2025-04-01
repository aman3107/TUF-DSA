#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int si, int mid, int ei)
{
  int n1 = mid - si + 1;
  int n2 = ei - mid;
  int arr1[n1 + 1];
  int arr2[n2 + 1];
  for (int i = 0; i < n1; i++)
  {
    arr1[i] = arr[si + i];
  }
  for (int i = 0; i < n2; i++)
  {
    arr2[i] = arr[mid + 1 + i];
  }
  int i = 0;
  int j = 0;
  int c = si;
  while (i < n1 && j < n2)
  {
    if (arr1[i] <= arr2[j])
    {
      arr[c] = arr1[i];
      i++;
      c++;
    }
    else if (arr2[j] < arr1[i])
    {
      arr[c] = arr2[j];
      j++;
      c++;
    }
  }
  while (i < n1)
  {
    arr[c] = arr1[i];
    i++;
    c++;
  }
  while (j < n2)
  {
    arr[c] = arr2[j];
    j++;
    c++;
  }
}

void merge_Sort(vector<int> &arr, int si, int ei)
{
  if (si >= ei)
  {
    return;
  }
  int mid = (si + ei) / 2;
  merge_Sort(arr, si, mid);
  merge_Sort(arr, mid + 1, ei);
  merge(arr, si, mid, ei);

  // TC = O(NlogN)
  // SC = O(N)
}

vector<int> mergeSort(vector<int> &nums)
{
  if (nums.size() == 0 || nums.size() == 1)
  {
    return nums;
  }
  merge_Sort(nums, 0, nums.size() - 1);
  return nums;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }
  vector<int> ans = mergeSort(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}