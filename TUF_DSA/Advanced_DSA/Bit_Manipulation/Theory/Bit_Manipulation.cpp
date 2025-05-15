#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
{
  k = 1 << (k - 1);
  return (n & k) != 0;
}

int setIthBit(int n, int k)
{
  k = 1 << (k - 1);
  return (n | k);
}

int clearIthBit(int n, int k)
{
  k = ~(1 << (k - 1));
  return n & k;
}

vector<int> bitManipulation(int num, int i)
{
  // Write your code here.
  int bitValue = checkKthBit(num, i);
  int setValue = setIthBit(num, i);
  int clearValue = clearIthBit(num, i);
  vector<int> ans;
  ans.push_back(bitValue);
  ans.push_back(setValue);
  ans.push_back(clearValue);
  return ans;
}

int main()
{
  int n;
  int k;
  cin >> n >> k;
  vector<int> ans = bitManipulation(n, k);
  for (int a : ans)
  {
    cout << a << "  ";
  }
  cout << endl;
}