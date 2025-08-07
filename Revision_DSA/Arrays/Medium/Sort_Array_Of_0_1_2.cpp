#include <bits/stdc++.h>
using namespace std;

/*
🧠 Intuition:
We want to sort the array in a single pass using constant space — without using built-in sort.
Key idea:
Use three pointers:
i for tracking 0s
j for current index
k for tracking 2s
This is called the Dutch National Flag Algorithm, proposed by Edsger Dijkstra.

🧭 Approach:
1. Initialize three pointers:
i = 0 (next position of 0)
j = 0 (current element under evaluation)
k = n - 1 (next position of 2)

2. Iterate while j <= k:
If nums[j] == 0:
→ swap nums[i] and nums[j]
→ move i++ and j++
If nums[j] == 1:
→ move j++ (1 is in the correct middle section)
If nums[j] == 2:
→ swap nums[j] and nums[k]
→ move k--
→ do not move j because the swapped element needs to be checked

Time and Space Complexity:
Time: O(n) — only one pass through the array
Space: O(1) — in-place sorting
*/

void sortZeroOneTwo(vector<int> &nums)
{
  int i = 0;
  int j = 0;
  int k = nums.size() - 1;
  while (j <= k)
  {
    if (nums[j] == 1)
    {
      j++;
    }
    else if (nums[j] == 0)
    {
      swap(nums[i], nums[j]);
      i++;
      j++;
    }
    else
    {
      swap(nums[j], nums[k]);
      k--;
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
  sortZeroOneTwo(arr);
  for (auto &it : arr)
  {
    cout << it << " ";
  }
  cout << endl;
}