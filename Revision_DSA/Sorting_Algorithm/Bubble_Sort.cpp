#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < n - i; j++)
    {
      if (arr[j - 1] > arr[j])
      {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {

    int data;
    cin >> data;
    arr.push_back(data);
  }
  bubbleSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}