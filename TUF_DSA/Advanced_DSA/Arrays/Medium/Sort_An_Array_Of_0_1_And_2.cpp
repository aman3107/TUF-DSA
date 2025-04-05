#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwoBetter(vector<int> &nums)
{
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 0)
      cnt0++;
    else if (nums[i] == 1)
      cnt1++;
    else
      cnt2++;
  }
  for (int i = 0; i < cnt0; i++)
    nums[i] = 0;
  for (int i = cnt0; i < cnt0 + cnt1; i++)
    nums[i] = 1;
  for (int i = cnt0 + cnt1; i < nums.size(); i++)
    nums[i] = 2;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void sortZeroOneTwo(vector<int> &nums)
{
  int n = nums.size();
  int i = 0;
  int k = 0;
  int j = n - 1;
  while (k <= j)
  {
    if (nums[k] == 0)
    {
      swap(nums[i], nums[k]);
      i++;
      k++;
    }
    else if (nums[k] == 1)
    {
      k++;
    }
    else
    {
      swap(nums[k], nums[j]);
      j--;
    }
  }
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
  sortZeroOneTwoBetter(v);
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}