#include <iostream>
using namespace std;

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

int main()
{
  int n;
  cin >> n;
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
  pattern_10(n);
}