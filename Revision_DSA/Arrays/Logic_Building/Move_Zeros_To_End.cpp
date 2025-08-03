#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
We want to move all 0s to the end of the array without changing the relative order of the non-zero elements.
So instead of finding the first 0, your version keeps a pointer j that always tracks the position to place the next non-zero element.

🧠 Approach:
Initialize j = 0 → This pointer will mark where the next non-zero element should go.
Loop over the array with i from 0 to n-1:
If nums[i] != 0, swap nums[i] with nums[j], and move j forward by one.
This way:
All non-zero elements are brought to the front in order.
All zeros are pushed to the end because the remaining indices after j will naturally be zeros.


*/

void moveZeroes(vector<int> &nums)
{
  int j = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
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
  moveZeroes(arr);
  for (auto &it : arr)
  {
    cout << it << " ";
  }
}