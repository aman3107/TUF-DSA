#include <bits/stdc++.h>
using namespace std;

void insertioneSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    int pac = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > pac)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = pac;
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
  insertioneSort(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}