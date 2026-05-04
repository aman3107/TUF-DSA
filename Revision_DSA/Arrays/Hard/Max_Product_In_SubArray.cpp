#include <bits/stdc++.h>
using namespace std;

int maxProductBetter(vector<int> &nums)
{
  int n = nums.size();
  int prefix = 1;
  int suffix = 1;
  int maxProduct = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (prefix == 0)
      prefix = 1;
    if (suffix == 0)
      suffix = 1;

    prefix *= nums[i];
    suffix *= nums[n - i - 1];
    maxProduct = max(maxProduct, max(suffix, prefix));
  }
  return maxProduct;
}

int maxProductBrute(vector<int> &nums)
{
  int result = nums[0];
  for (int i = 0; i < nums.size(); i++)
  {
    int prod = nums[i];
    for (int j = i + 1; j < nums.size(); j++)
    {
      prod = prod * nums[j];
      result = max(result, prod);
    }
    result = max(result, prod);
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums.push_back(data);
  }
}