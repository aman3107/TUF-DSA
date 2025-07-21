#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int distinctPrimeFactors(vector<int> &nums)
  {
    vector<int> spf(1001 + 1, 1);
    for (int i = 0; i <= 1000; i++)
    {
      spf[i] = i;
    }
    for (int i = 2; i * i <= 1000; i++)
    {
      if (spf[i] == i)
      {
        for (int j = i * i; j <= 1000; j += i)
        {
          if (spf[j] == j)
          {
            spf[j] = i;
          }
        }
      }
    }
    unordered_set<int> uniquePrimes;
    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      while (n != 1)
      {
        uniquePrimes.insert(spf[n]);
        n = n / spf[n];
      }
    }
    return uniquePrimes.size();
  }
};