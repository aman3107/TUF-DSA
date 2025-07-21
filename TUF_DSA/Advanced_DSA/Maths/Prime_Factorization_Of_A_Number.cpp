#include <bits/stdc++.h>
using namespace std;

/*
✅ 🔍 Intuition:
We want to find the prime factorization of multiple numbers (stored in queries[]), but doing it from scratch for every number is inefficient.
So, instead of dividing by every number repeatedly, we precompute the smallest prime factor (SPF) for all numbers up to 1e5.
Then, we can quickly factorize any number by dividing it by its smallest prime repeatedly.
This method brings down the time complexity per query to O(log n) after a one-time sieve precomputation in O(n log log n).

✅ 🧠 Approach:
1. SPF Array Initialization:
vector<int> spf(1e5 + 1, 1);
for (int i = 0; i <= 1e5; i++) {
    spf[i] = i;
}
spf[i] will eventually store the smallest prime factor of i.
Initially, we assume every number is its own smallest factor.

2. Sieve of Eratosthenes (SPF version):
for (int i = 2; i * i <= 1e5; i++) {
    if (spf[i] == i) {
        for (int j = i * i; j <= 1e5; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }
}
For every prime i, we iterate through its multiples starting from i*i
If a number j hasn't been marked yet (spf[j] == j), we set its smallest prime factor to i.

3. Processing the Queries:
for (int i = 0; i < queries.size(); i++) {
    vector<int> temp;
    int n = queries[i];
    while (n != 1) {
        temp.push_back(spf[n]);
        n = n / spf[n];
    }
    ans.push_back(temp);
}
For each number in queries, we:
Keep dividing the number by its smallest prime factor until it becomes 1.
Collect each factor in a temporary vector.
Add the result to the final ans vector.

✅ Example:
For queries = {60, 84}:
60 → [2, 2, 3, 5]
84 → [2, 2, 3, 7]

✅ Time Complexity:
Preprocessing SPF: O(n log log n)
Each query factorization: O(log n)
Total for Q queries: O(Q * log n)
*/

vector<vector<int>> primeFactors(vector<int> &queries)
{
  // your code goes here
  vector<int> spf(1e5 + 1, 1); // Creating an spf array of size 1e5+1
  for (int i = 0; i <= 1e5; i++)
  {
    spf[i] = i; // Initialize all the indexes with their indexes value
  }
  for (int i = 2; i * i <= 1e5; i++)
  {
    if (spf[i] == i) // When arr[index]==index. It's a prime factor
    {
      for (int j = i * i; j <= 1e5; j += i)
      {
        if (spf[j] == j) // If only if spf[j]==j means 4 == 4
        {
          spf[j] = i; // Then assign the prime factor value
        }
      }
    }
  }
  vector<vector<int>> ans;
  for (int i = 0; i < queries.size(); i++)
  {
    vector<int> temp;
    int n = queries[i]; // taking the num
    while (n != 1)      // When n is not becomes 1
    {
      temp.push_back(spf[n]); // push the num
      n = n / spf[n];         // divide the num with spf[n] value
    }
    ans.push_back(temp);
  }
  return ans;
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
  vector<vector<int>> ans = primeFactors(nums);
  for (auto it : ans)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
}
