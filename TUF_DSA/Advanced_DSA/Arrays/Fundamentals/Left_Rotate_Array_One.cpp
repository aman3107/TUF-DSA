#include <bits/stdc++.h>
using namespace std;

void rotateArrayByOne(vector<int> &nums)
{
  if (nums.size() <= 1)
  {
    return;
  }
  int num = nums[0];
  for (int i = 0; i < nums.size() - 1; i++)
  {
    nums[i] = nums[i + 1];
  }
  nums[nums.size() - 1] = num;
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
  rotateArrayByOne(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}