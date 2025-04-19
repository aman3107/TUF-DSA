#include <bits/stdc++.h>
using namespace std;

double medianBetter(vector<int> &arr1, vector<int> &arr2)
{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int n = n1 + n2;
  int ind2 = n / 2;
  int ind1 = ind2 - 1;
  int el1 = 0;
  int el2 = 0;
  int c = 0;
  int i = 0, j = 0;
  while (i < n1 && j < n2)
  {
    if (arr1[i] <= arr2[j])
    {
      if (ind1 == c)
        el1 = arr1[i];
      if (ind2 == c)
        el2 = arr1[i];
      c++;
      i++;
    }
    else
    {
      if (ind1 == c)
        el1 = arr2[j];
      if (ind2 == c)
        el2 = arr2[j];
      c++;
      j++;
    }
  }
  while (i < n1)
  {
    if (ind1 == c)
      el1 = arr1[i];
    if (ind2 == c)
      el2 = arr1[i];
    c++;
    i++;
  }
  while (j < n2)
  {
    if (ind1 == c)
      el1 = arr2[j];
    if (ind2 == c)
      el2 = arr2[j];
    c++;
    j++;
  }

  if (n % 2 == 1)
  {
    return (double)el2;
  }
  else
  {
    return (double)((double)el1 + el2) / 2.0;
  }
}

double medianBrute(vector<int> &arr1, vector<int> &arr2)
{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int n = n1 + n2;
  vector<int> merge;
  int i = 0, j = 0;
  while (i < n1 && j < n2)
  {
    if (arr1[i] <= arr2[j])
    {
      merge.push_back(arr1[i]);
      i++;
    }
    else
    {
      merge.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n1)
  {
    merge.push_back(arr1[i]);
    i++;
  }
  while (j < n2)
  {
    merge.push_back(arr2[j]);
    j++;
  }
  if (n % 2 == 1)
  {
    return (double)merge[n / 2];
  }
  else
  {
    return (double)(((double)merge[n / 2] + (double)merge[(n / 2) - 1]) / 2.0);
  }
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> arr1;
  vector<int> arr2;
  for (int i = 0; i < n1; i++)
  {
    int val;
    cin >> val;
    arr1.push_back(val);
  }
  for (int i = 0; i < n2; i++)
  {
    int val;
    cin >> val;
    arr2.push_back(val);
  }

  cout << medianBrute(arr1, arr2) << endl;
}