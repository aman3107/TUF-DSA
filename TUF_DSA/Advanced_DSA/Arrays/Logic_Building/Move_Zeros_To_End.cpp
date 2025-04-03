#include <bits/stdc++.h>
using namespace std;

void moveZeroes2(vector<int> &nums)
{
  int j = -1;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
  {
    return;
  }
  for (int i = j + 1; i < nums.size(); i++)
  {
    if (nums[i] != 0)
    {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
      j++;
    }
  }
}

void moveZeroes(vector<int> &nums)
{
  int i = 0;
  int j = 1;
  while (i < nums.size() && j < nums.size())
  {

    if (nums[i] != 0)
    {
      i++;
    }
    else if (nums[j] == 0 || j < i)
    {
      j++;
    }

    else
    {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
      i++;
      j++;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }
  moveZeroes2(v);
  for (auto a : v)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}