#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicateBrute(vector<int> &nums)
{
  int n = nums.size();
  for (int i = 1; i < n; i = i + 2)
  {
    if (nums[i - 1] != nums[i])
    {
      return nums[i];
    }
  }
  return 0;
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
  cout << singleNonDuplicateBrute(v) << endl;
}