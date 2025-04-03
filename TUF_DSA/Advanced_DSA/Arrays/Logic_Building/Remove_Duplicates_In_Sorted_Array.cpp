#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();
  int c = 0;
  for (int i = 1; i < n; i++)
  {
    if (nums[c] != nums[i])
    {
      c++;
      nums[c] = nums[i];
    }
  }
  return c + 1;
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
  int c = removeDuplicates(v);
  for (int i = 0; i < c; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}