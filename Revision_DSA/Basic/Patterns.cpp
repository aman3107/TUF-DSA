#include <bits/stdc++.h>
using namespace std;

void pattern22(int n)
{
  for (int i = 0; i < 2 * n - 1; i++)
  {
    for (int j = 0; j < 2 * n - 1; j++)
    {
      int top = i;
      int left = j;
      int bottom = (2 * n - 2) - i;
      int right = (2 * n - 2) - j;
      int value = n - min(min(top, bottom), min(right, left));
      cout << value << " ";
    }
    cout << endl;
  }
}

void pattern21(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (i == 1 || i == n)
    {
      for (int stars = 1; stars <= n; stars++)
      {
        cout << "*";
      }
    }
    else
    {
      cout << "*";
      for (int spaces = 1; spaces <= n - 2; spaces++)
      {
        cout << " ";
      }
      cout << "*";
    }
    cout << endl;
  }
}

void pattern20(int n)
{
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    if (i > n)
    {
      for (int stars = 1; stars <= n - (i - n); stars++)
      {
        cout << "*";
      }
      for (int spaces = 1; spaces <= 2 * (i - n); spaces++)
      {
        cout << " ";
      }
      for (int stars = 1; stars <= n - (i - n); stars++)
      {
        cout << "*";
      }
    }
    else
    {
      for (int stars = 1; stars <= i; stars++)
      {
        cout << "*";
      }
      for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
      {
        cout << " ";
      }
      for (int stars = 1; stars <= i; stars++)
      {
        cout << "*";
      }
    }
    cout << endl;
  }
}

void pattern19(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int stars = 1; stars <= (n - i); stars++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * i; spaces++)
    {
      cout << " ";
    }
    for (int stars = 1; stars <= (n - i); stars++)
    {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int stars = 1; stars <= i; stars++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
    {
      cout << " ";
    }
    for (int stars = 1; stars <= i; stars++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern18(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char ch = 'A' + (n - i);
    for (int j = 1; j <= i; j++)
    {
      cout << ch << " ";
      ch++;
    }
    cout << endl;
  }
}

void pattern17(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int spaces = 1; spaces <= n - i; spaces++)
    {
      cout << " ";
    }
    char ch = 'A';
    for (int j = 1; j <= i; j++)
    {
      cout << ch;
      ch++;
    }
    ch = ch - 2;
    for (int k = 1; k <= i - 1; k++)
    {
      cout << ch;
      ch--;
    }
    cout << endl;
  }
}

void pattern16(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char ch = 'A' + (i - 1);
    for (int j = 1; j <= i; j++)
    {
      cout << ch;
    }
    cout << endl;
  }
}

void pattern15(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char ch = 'A';
    for (int j = 1; j <= (n - i) + 1; j++)
    {
      cout << ch;
      ch++;
    }
    cout << endl;
  }
}

void pattern14(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char ch = 'A';
    for (int j = 1; j <= i; j++)
    {
      cout << ch;
      ch++;
    }
    cout << endl;
  }
}

void pattern13(int n)
{
  int num = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << num << " ";
      num++;
    }
    cout << endl;
  }
}

void pattern12(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int num1 = 1; num1 <= i; num1++)
    {
      cout << num1;
    }
    for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
    {
      cout << " ";
    }
    for (int num2 = i; num2 > 0; num2--)
    {
      cout << num2;
    }
    cout << endl;
  }
}

void pattern11(int n)
{
  for (int i = 1; i <= n; i++)
  {
    int a = i % 2 == 0 ? 0 : 1;
    for (int j = 1; j <= i; j++)
    {
      cout << a;
      a = !a;
    }
    cout << endl;
  }
}

void pattern10(int n)
{
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    if (i > n)
    {
      for (int stars = 1; stars <= n - (i - n); stars++)
      {
        cout << "*";
      }
    }
    else
    {
      for (int stars = 1; stars <= i; stars++)
      {
        cout << "*";
      }
    }
    cout << endl;
  }
}

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
  pattern22(n);
}