#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
  int posIndex = 0;
  int negIndex = 1;
  int n = nums.size();
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (nums[i] < 0)
    {
      ans[negIndex] = nums[i];
      negIndex += 2;
    }
    else
    {
      ans[posIndex] = nums[i];
      posIndex += 2;
    }
  }
  return ans;

  // TC = O(N)
  // SC = O(N)
}

vector<int> rearrangeArrayBrute(vector<int> &nums)
{
  vector<int> neg;
  vector<int> pos;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= 0)
    {
      pos.push_back(nums[i]);
    }
    else
    {
      neg.push_back(nums[i]);
    }
  }
  for (int i = 0; i < n / 2; i++)
  {

    nums[2 * i] = pos[i];
    nums[2 * i + 1] = neg[i];
  }
  return nums;

  // TC = O(N+M)
  // SC = O(N)
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
  vector<int> ans = rearrangeArray(v);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}