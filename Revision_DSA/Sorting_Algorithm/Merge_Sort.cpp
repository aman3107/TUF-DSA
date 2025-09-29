#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int high, int mid)
{

  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void helper(vector<int> &arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int mid = (l + r) / 2;

  helper(arr, l, mid);
  helper(arr, mid + 1, r);
  merge(arr, l, r, mid);
}

void mergeSort(vector<int> &arr)
{
  int n = arr.size();
  helper(arr, 0, n - 1);
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
  mergeSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
