#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &nums)
{
  for (int i = 0; i < nums.size() - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[j] < nums[minIndex])
      {
        minIndex = j;
      }
    }

    int temp = nums[i];
    nums[i] = nums[minIndex];
    nums[minIndex] = temp;
  }
  return nums;

  // TC = O(n2)
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
  vector<int> ans = selectionSort(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}