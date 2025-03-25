#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
  int copy = n;
  int reverseNum = 0;
  while (copy > 0)
  {
    int lastDigit = copy % 10;
    reverseNum = reverseNum * 10 + lastDigit;
    copy = copy / 10;
  }
  return (reverseNum == n);

  // T.C = O(log n)
  // S.C = O(1)
}

int reverseNumber(int n)
{
  int num = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    num = num * 10 + lastDigit;
    n = n / 10;
  }
  return num;

  // T.C =  O(Log n)
  // S.C = O(1)
}

int countOddDigit(int n)
{
  int countOdd = 0;
  while (n > 0)
  {
    int digit = n % 10;
    if (digit % 2 != 0)
    {
      countOdd++;
    }
    n = n / 10;
  }
  return countOdd;

  // T.C = O(log n)
  // S.C = O(1)
}

int countDigit(int n)
{
  if (n == 0)
  {
    return 1;
  }
  int count = 0;
  while (n > 0)
  {
    count++;
    n = n / 10;
  }
  return count;

  // T.C = O(log n)
  // S.C = O(1)
}

int largestDigit(int n)
{
  int largestDigit = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    if (lastDigit > largestDigit)
    {
      largestDigit = lastDigit;
    }
    n = n / 10;
  }
  return largestDigit;

  // T.C = O(log n)
  // S.C =  O(1)
}

int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  int fact = 1;
  for (int i = 1; i <= n; i++)
  {
    fact = fact * i;
  }
  return fact;

  // T.C = O(n)
  // S.C = O(1)
}

bool isArmstrong(int n)
{
  int armstrongNum = 0;
  int count = countDigit(n);
  int copy = n;
  while (copy > 0)
  {
    int lastDigit = copy % 10;
    armstrongNum = armstrongNum + round(pow(lastDigit, count));
    copy = copy / 10;
  }
  return (armstrongNum == n);

  // T.C = O(log n);
  // S.C = O(1)
}

bool isPerfect(int n)
{
  if (n == 1)
  {
    return false;
  }
  int sum = 0;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      sum = sum + i;
      if (n / i != n && n / i != i)
      {
        sum = sum + (n / i);
      }
    }
  }
  return (sum == n);

  // T.C = O(sqrt(n))
  // S.C =  O(1)
}

bool isPrime(int n)
{
  if (n == 1)
  {
    return false;
  }
  for (int d = 2; d <= sqrt(n); d++)
  {
    if (n % d == 0)
    {
      return false;
    }
  }
  return true;

  // T.C = O(sqrt(n))
  // S.C =  O(1)
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

  // T.C = O(N*sqrt(n))
  // S.C = O(1)
}

int gcd(int n1, int n2)
{
  while (n1 != 0 && n2 != 0)
  {
    if (n1 > n2)
    {
      n1 = n1 % n2;
    }
    else
    {
      n2 = n2 % n1;
    }
  }
  if (n1 == 0)
  {
    return n2;
  }
  else
  {
    return n1;
  }

  // T.C = O(log min(n1,n2))
  // S.C = O(1)
}

int LCM(int n1, int n2)
{
  return (n1 * n2 / (gcd(n1, n2)));
}

int main()
{
  int n1, n2;
  cout << "Enter value of n1 and n2 :" << endl;
  cin >> n1 >> n2;

  // cout << countDigit(n) << endl;
  // cout << countOddDigit(n) << endl;
  // cout << reverseNumber(n) << endl;
  // cout << isPalindrome(n) << endl;
  // cout << largestDigit(n) << endl;
  // cout << factorial(n) << endl;
  // cout << isArmstrong(n) << endl;
  // cout << isPerfect(n) << endl;
  // cout << isPrime(n) << endl;
  // cout << primeUptoN(n) << endl;
  cout << gcd(n1, n2) << endl;
  cout << LCM(n1, n2) << endl;
}