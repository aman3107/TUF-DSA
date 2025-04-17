#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int k)
{
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((i * j) % k == 0 && nums[i] == nums[j])
      {
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    nums.push_back(val);
  }
  int k;
  cin >> k;
  cout << countPairs(nums, k) << endl;
}
