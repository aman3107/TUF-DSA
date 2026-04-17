#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> arr, int n)
{
  int l = 0;
  int r = n - 1;
  while (l < r)
  {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }
}

bool arraySortedOrNot(vector<int> arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] > arr[i])
    {
      return false;
    }
  }
  return true;
}

int countOdd(vector<int> arr, int n)
{
  int countOdd = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 != 0)
    {
      countOdd++;
    }
  }
  return countOdd;
}

int sum(vector<int> arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    v.push_back(data);
  }
  int ans = sum(v, n);
  cout << ans;
}