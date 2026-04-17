#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
  // your code goes here
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

int primeUptoN(int n)
{
  int countPrime = 0;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime(i))
    {
      countPrime++;
    }
  }
  return countPrime;
}

bool isPerfect(int n)
{
  if (n <= 1)
    return false;
  int sum = 1;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      sum = sum + i;
      if (i != n / i)
      {
        sum = sum + n / i;
      }
    }
  }
  return (n == sum);
}

bool isArmstrong(int n)
{
  int count = 0;
  int m = n;
  while (m > 0)
  {
    count++;
    m = m / 10;
  }
  int k = n;
  int armstrong = 0;
  while (k > 0)
  {
    int num = k % 10;
    armstrong = armstrong + pow(num, count);
    k = k / 10;
  }
  return (armstrong == n);
}

int factorial(int n)
{
  int fact = 1;
  for (int i = 1; i <= n; i++)
  {
    fact = fact * i;
  }
  return fact;
}

int largestDigit(int n)
{
  int max = 0;
  while (n > 0)
  {
    int rem = n % 10;
    if (rem > max)
    {
      max = rem;
    }
    n = n / 10;
  }
  return max;
}

bool isPalindrome(int n)
{
  int m = n;
  int revNum = 0;
  while (m > 0)
  {
    int rem = m % 10;
    revNum = revNum * 10 + rem;
    m = m / 10;
  }
  return (revNum == n);
}

int reverseNumber(int n)
{
  int revNum = 0;
  while (n > 0)
  {
    int rem = n % 10;
    revNum = revNum * 10 + rem;
    n = n / 10;
  }
  return revNum;
}

int countOddDigit(int n)
{
  int countOdd = 0;
  while (n > 0)
  {
    if ((n % 10) % 2 != 0)
    {
      countOdd++;
    }
    n = n / 10;
  }
  return countOdd;
}

int countDigit(int n)
{
  if (n == 0)
    return 1;
  int count = 0;
  while (n > 0)
  {
    count++;
    n = n / 10;
  }

  return count;
}

int main()
{
  int n;
  cin >> n;
  cout << primeUptoN(n);
}