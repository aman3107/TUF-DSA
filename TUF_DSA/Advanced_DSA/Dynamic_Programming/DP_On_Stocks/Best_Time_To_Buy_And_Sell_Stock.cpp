#include <bits/stdc++.h>
using namespace std;

int stockBuySell(vector<int> arr, int n)
{
  int mini = arr[0];
  int profit = 0;
  for (int i = 1; i < n; i++)
  {
    int cost = arr[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, arr[i]);
  }
  return profit;
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
  cout << stockBuySell(arr, n) << endl;
}