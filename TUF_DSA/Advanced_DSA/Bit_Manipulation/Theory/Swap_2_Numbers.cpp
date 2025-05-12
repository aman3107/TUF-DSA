#include <bits/stdc++.h>
using namespace std;

void swap2Numbers(int &a, int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main()
{
  int a;
  int b;
  cin >> a >> b;
  swap2Numbers(a, b);
  cout << a << " " << b << endl;
}