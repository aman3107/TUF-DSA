#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int minInd = i;
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[j] < arr[minInd])
      {
        minInd = j;
      }
    }
    int temp = arr[minInd];
    arr[minInd] = arr[i];
    arr[i] = temp;
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
  selectionSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}