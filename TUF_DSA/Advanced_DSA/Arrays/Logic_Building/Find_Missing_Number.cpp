#include <bits/stdc++.h>
using namespace std;

int missingNumber2(vector<int> &nums)
{
  int n = nums.size();
  int xor1 = 0;
  int xor2 = 0;
  for (int i = 0; i < n; i++)
  {
    xor1 = xor1 ^ (i + 1);
    xor2 = xor2 ^ nums[i];
  }
  return xor1 ^ xor2;
}

int missingNumber1(vector<int> &nums)
{
  int n = nums.size();
  int sum1 = (n * (n + 1)) / 2;
  int sum2 = 0;
  for (auto num : nums)
  {
    sum2 += num;
  }
  return sum1 - sum2;
}

int missingNumber(vector<int> &nums)
{
  int n = nums.size();
  int num = (n * (n + 1)) / 2;
  for (int i = 0; i < n; i++)
  {
    num -= nums[i];
  }
  return num;

  // TC = O(n)
  // SC = O(1)
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
  cout << missingNumber2(v) << endl;
}