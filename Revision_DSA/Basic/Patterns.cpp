#include <bits/stdc++.h>
using namespace std;

void pattern8(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int spaces = 1; spaces < i; spaces++)
    {
      cout << " ";
    }
    for (int stars = 1; stars <= 2 * (n - i) + 1; stars++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern7(int n)
{
  int i = 1;
  while (i <= n)
  {
    int spaces = 1;
    while (spaces <= n - i)
    {
      cout << " ";
      spaces++;
    }
    int stars = 1;
    while (stars <= 2 * i - 1)
    {
      cout << "*";
      stars++;
    }
    cout << endl;
    i++;
  }
}

void pattern6(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= n - i; j++)
    {
      cout << j;
    }
    cout << endl;
  }
}

void pattern5(int n)
{
  int i = 0;
  while (i < n)
  {
    int j = n - i;
    while (j > 0)
    {
      cout << "*";
      j--;
    }
    cout << endl;
    i++;
  }
}

void pattern4(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i;
    }
    cout << endl;
  }
}

void pattern3(int n)
{
  int i = 0;
  while (i < n)
  {
    int num = 1;
    int j = 0;
    while (j <= i)
    {
      cout << num;
      num++;
      j++;
    }
    cout << endl;
    i++;
  }
}

void pattern2(int n)
{
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= i)
    {
      cout << "*";
      j++;
    }
    cout << endl;
    i++;
  }
}

void pattern1(int n)
{
  int i = 0;
  while (i < n)
  {
    int j = 0;
    while (j < n)
    {
      cout << "*";
      j++;
    }
    cout << endl;
    i++;
  }
}

void pattern9(int n)
{
  pattern7(n);
  pattern8(n);
}
int main()
{
  int n;
  cin >> n;
  pattern9(n);
}