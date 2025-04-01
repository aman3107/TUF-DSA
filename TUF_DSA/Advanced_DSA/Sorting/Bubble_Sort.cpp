#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> &nums)
{
  for (int i = 0; i < nums.size() - 1; i++)
  {
    int didSwap = 0;
    for (int j = 0; j < nums.size() - i - 1; j++)
    {
      if (nums[j] > nums[j + 1])
      {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
        didSwap = 1;
      }
    }
    if (didSwap == 0)
    {
      break;
    }
  }
  return nums;
  // TC = O(N2)
  // SC = O(n)
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }
  vector<int> ans = bubbleSort(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}