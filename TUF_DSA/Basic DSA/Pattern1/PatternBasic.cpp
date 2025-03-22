#include <iostream>
using namespace std;

void pattern1(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern2(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern3(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    cout << endl;
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

void pattern5(int n)
{

  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i + 1; j > 0; j--)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern6(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << j;
    }
    cout << endl;
  }
}

void pattern7(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i; j++)
    {
      cout << " ";
    }
    for (int k = 1; k <= 2 * i - 1; k++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern8(int n)
{
  for (int i = n; i > 0; i--)
  {
    for (int j = 1; j <= n - i; j++)
    {
      cout << " ";
    }
    for (int k = 1; k <= 2 * i - 1; k++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void erect_pyramid(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int k = 1; k <= n - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void invert_pyramid(int n)
{
  for (int i = n; i > 0; i--)
  {
    for (int k = 1; k <= n - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern_9(int n)
{
  erect_pyramid(n);
  invert_pyramid(n);
}

void patternN(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void patter_N_Minus_1(int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern_10(int n)
{
  patternN(n);
  patter_N_Minus_1(n);
}

void pattern11(int n)
{
  for (int i = 1; i <= n; i++)
  {
    int a = 1;
    int b = 0;
    for (int j = 1; j <= i; j++)
    {
      if (i % 2 == 0)
      {
        cout << b;
        int temp = a;
        a = b;
        b = temp;
      }
      else
      {
        cout << a;
        int temp = a;
        a = b;
        b = temp;
      }
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter num value : " << endl;
  cin >> n;
  // pattern1(n);
  // pattern2(n);
  // pattern3(n);
  // pattern4(n);
  // pattern5(n);
  // pattern6(n);
  // pattern7(n);
  // pattern8(n);
  // pattern11(n);

  /*
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  */

  // pattern_9(n);
  // pattern_10(n);
}