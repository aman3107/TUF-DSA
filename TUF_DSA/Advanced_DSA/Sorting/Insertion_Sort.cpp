#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> &nums)
{
  for (int i = 1; i < nums.size(); i++)
  {
    int pac = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > pac)
    {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = pac;
  }
  return nums;
  // TC = O(N2)
  // SC = O(1)
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
  vector<int> ans = insertionSort(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}