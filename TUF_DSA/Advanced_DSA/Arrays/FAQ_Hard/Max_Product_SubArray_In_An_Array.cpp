#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
  int prefix = 0;
  int suffix = 0;
  int n = nums.size();
  int maxProd = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (prefix == 0)
    {
      prefix = 1;
    }
    if (suffix == 0)
    {
      suffix = 1;
    }
    prefix *= nums[i];
    suffix *= nums[n - i - 1];
    maxProd = max(maxProd, max(prefix, suffix));
  }
  return maxProd;
}

int maxProductBrute(vector<int> &nums)
{
  int n = nums.size();
  int result = nums[0];
  for (int i = 0; i < n - 1; i++)
  {
    int p = nums[i];
    for (int j = i + 1; j < n; j++)
    {
      p *= nums[j];
    }
    result = max(result, p);
  }
  return result;
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
  cout << maxProduct(v) << endl;
}