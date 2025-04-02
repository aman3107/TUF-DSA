#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
  while (start < end)
  {
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
}

void rotateArrayRight(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;
  reverse(nums, 0, n - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
}

void rotateArrayLeft(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
  reverse(nums, 0, n - 1);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  int k;
  cin >> k;
  rotateArrayLeft(arr, k);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}