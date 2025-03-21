#include <iostream>
using namespace std;

int main()
{
  int age;
  cin >> age;
  if (age >= 18)
  {
    cout << "Adult" << endl;
  }
  else if (age < 18 && age >= 10)
  {
    cout << "Teen" << endl;
  }
  else
  {
    cout << "Child" << endl;
  }
}