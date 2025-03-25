#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
  int arraySum = 0;
  for (int i = 0; i < n; i++)
  {
    arraySum = arraySum + arr[i];
  }
  return arraySum;
  // TC = O(n)
  // SC = O(1)
}

int countOdd(int arr[], int n)
{
  int oddCount = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      oddCount++;
    }
  }
  return oddCount;
}

void reverse(int arr[], int n)
{
  int i = 0;
  int j = n - 1;
  while (i < j)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
  // TC = O(N)
  // SC = O(1)
}

bool arraySortedOrNot(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] > arr[i])
    {
      return false;
    }
  }
  return true;

  // TC = O(n)
  // SC =  O(1)
}

int main()
{
  int n;
  cout << "Enter value of n :" << endl;
  cin >> n;

  int arr[n];
  cout << "Enter elements in the array :" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // cout << sum(arr, n);
  // cout << countOdd(arr, n);
  reverse(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << arraySortedOrNot(arr, n) << endl;
}