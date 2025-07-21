#include <bits/stdc++.h>
using namespace std;

/*
✅ 🔍 Intuition:
We want to find all prime numbers from 2 to n.
A prime number is a number greater than 1 that has no divisors other than 1 and itself.
To do this efficiently, we use the Sieve of Eratosthenes — a classic algorithm to find all primes up to a number n in O(n log log n) time.

✅ 🧠 Approach:
Initialize a vector prime of size n+1 and mark all numbers as 1 (which means "prime" initially).
Start from 2, the first prime number.
For every number i from 2 to √n
If prime[i] == 1 (i.e., i is prime):
Mark all multiples of i starting from i*i as not prime (prime[j] = 0), because they are divisible by i.
After the sieve process, the indices i where prime[i] == 1 are all the prime numbers from 2 to n.
Store these i values in the result vector ans.
Return the vector ans which contains all primes ≤ n.

✅ Example:
Let’s say n = 10
Initially: prime = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
After sieve:
2 → mark 4, 6, 8, 10 as not prime
3 → mark 9 as not prime
Final prime indices with prime[i] == 1: 2, 3, 5, 7
So, result = [2, 3, 5, 7]

✅ Time Complexity:
O(n log log n) — for sieve
O(n) — to collect prime numbers
*/

vector<int> primeTillN(int n)
{
  // your code goes here
  vector<int> prime(n + 1, 1);
  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= n; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  vector<int> ans;
  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> ans = primeTillN(n);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}