#include <bits/stdc++.h>
using namespace std;

/*
You're given a binary array (consisting of only 0s and 1s), and the goal is to find the maximum number of consecutive 1s.

The key idea is:
➡️ Every time we see a 1, we increase the count of current streak.
➡️ If we see a 0, we reset the count to 0 because the streak breaks.
➡️ Throughout this process, we keep updating the maximum streak seen so far.

🧠 Approach:
Initialize two variables:
count = 0: current streak of consecutive 1s
maxOnes = 0: longest streak seen so far
Loop through each number in the array:
If the number is 1, increment count and update maxOnes with the maximum of maxOnes and count.
If the number is 0, reset count to 0.
After the loop ends, maxOnes holds the maximum number of consecutive 1s.

✅ Time and Space Complexity:
Time Complexity: O(n) – One pass through the array.

Space Complexity: O(1) – No extra space used.
*/

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int maxOnes = 0;
  int count = 0;
  for (auto &num : nums)
  {
    if (num == 1)
    {
      count++;
      maxOnes = max(maxOnes, count);
    }
    else
    {
      count = 0;
    }
  }
  return maxOnes;
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
  cout << findMaxConsecutiveOnes(arr);
}