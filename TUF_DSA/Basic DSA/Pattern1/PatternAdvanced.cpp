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

int main()
{
  int n;
  cout << "Enter num value :" << endl;
  cin >> n;
  pattern12(n);
}