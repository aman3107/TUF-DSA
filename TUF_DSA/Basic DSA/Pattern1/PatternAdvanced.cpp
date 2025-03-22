#include <iostream>
using namespace std;

void pattern12(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
    {
      cout << " ";
    }
    for (int j = i; j > 0; j--)
    {
      cout << j;
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

void pattern14(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      char ch = 'A' + (j - 1);
      cout << ch;
    }
    cout << endl;
  }
}

void pattern15(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      char ch = 'A' + (j - 1);
      cout << ch;
    }
    cout << endl;
  }
}

void pattern16(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      char ch = 'A' + i - 1;
      cout << ch;
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
    int totalChar = 2 * i - 1;
    int char_decreasing = totalChar / 2;
    int char_increasing = totalChar - char_decreasing;
    char ch = 'A';
    for (int k = 1; k <= char_increasing; k++)
    {
      ch = 'A' + k - 1;
      cout << ch;
    }
    ch = ch - 1;
    for (int k = char_decreasing; k > 0; k--)
    {
      cout << ch;
      ch = ch - 1;
    }
    cout << endl;
  }
}

void pattern18(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      char ch = 'A' + ((n - i - 1) + j);
      cout << ch;
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
      for (int j = 1; j <= n; j++)
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

void decreasingStars(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * (i - 1); spaces++)
    {
      cout << " ";
    }
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void increasingStars(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern19(int n)
{
  decreasingStars(n);
  increasingStars(n);
}

void increasingStartByOne(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * (n - i); spaces++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void decreasingStartByOne(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << "*";
    }
    for (int spaces = 1; spaces <= 2 * i; spaces++)
    {
      cout << " ";
    }
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern20(int n)
{
  increasingStartByOne(n);
  decreasingStartByOne(n - 1);
}

int main()
{
  int n;
  cout << "Enter num value :" << endl;
  cin >> n;
  // pattern12(n);
  // pattern13(n);
  // pattern14(n);
  // pattern15(n);
  // pattern16(n);
  // pattern17(n);
  // pattern18(n);
  // pattern21(n);
  // pattern19(n);
  pattern20(n);
}