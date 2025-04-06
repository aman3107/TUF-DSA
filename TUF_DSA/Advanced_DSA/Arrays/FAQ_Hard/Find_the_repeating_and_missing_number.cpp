#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
  long long n = nums.size();
  // S-Sn (x-y)
  // S2 - S2n (x2-y2)
  long long Sn = (n * (n + 1)) / 2;
  long long S = 0;
  long long S2 = 0;
  for (int i = 0; i < n; i++)
  {
    S += nums[i];
    S2 += (long long)nums[i] * (long long)nums[i];
  }
  long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
  long long eq1 = S - Sn;    // (x-y)
  long long eq2 = S2 - S2n;  // (x2-y2)
  long long eq3 = eq2 / eq1; // (x+y)
  long long x = (eq1 + eq3) / 2;
  long long y = eq3 - x;
  return {(int)x, (int)y};
}

vector<int> findMissingRepeatingNumbersBetter(vector<int> nums)
{
  int n = nums.size();
  int repeating = -1, missing = -1;
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  for (int i = 1; i <= n; i++)
  {
    if (mpp[i] == 2)
    {
      repeating = i;
    }
    else if (mpp[i] == 0)
    {
      missing = i;
    }

    if (repeating != -1 && missing != -1)
    {
      break;
    }
  }
  return {repeating, missing};
}

vector<int> findMissingRepeatingNumbersBrute(vector<int> nums)
{
  int n = nums.size();
  int repeating = -1, missing = -1;
  for (int i = 1; i <= n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (nums[j] == i)
      {
        cnt++;
      }
    }
    if (cnt == 2)
      repeating = i;
    else if (cnt == 0)
      missing = i;
    if (repeating != -1 && missing != -1)
    {
      break;
    }
  }
  return {repeating, missing};
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
  vector<int> ans = findMissingRepeatingNumbers(v);
  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}