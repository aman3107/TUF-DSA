#include <bits/stdc++.h>
using namespace std;

void reverseHelper(vector<int> &nums, int l, int r)
{
  while (l < r)
  {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
    l++;
    r--;
  }
}

void rotateArray(vector<int> &nums, int k)
{
  int n = nums.size();
  k = k % n;
  reverseHelper(nums, 0, k - 1);
  reverseHelper(nums, k, n - 1);
  reverseHelper(nums, 0, n - 1);
}

void rotateArrayByOne(vector<int> &nums)
{
  int first = nums[0];
  int n = nums.size();
  for (int i = 1; i < n; i++)
  {
    nums[i - 1] = nums[i];
  }
  nums[n - 1] = first;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int countOnes = 0;
  int maxCountOnes = 0;
  for (int num : nums)
  {
    if (num != 1)
    {
      countOnes = 0;
    }
    else
    {
      countOnes++;
      maxCountOnes = max(maxCountOnes, countOnes);
    }
  }
  return maxCountOnes;
}

int secondLargestElement(vector<int> &nums)
{
  // your code goes here
  int max = INT_MIN;
  int secMax = INT_MIN;
  for (int num : nums)
  {
    if (num > max)
    {
      secMax = max;
      max = num;
    }
    else if (num < max && num > secMax)
    {
      secMax = num;
    }
  }
  return secMax == INT_MIN ? -1 : secMax;
}

int largestElement(vector<int> &nums)
{
  int maxEle = nums[0];
  for (int i = 1; i < nums.size(); i++)
  {
    maxEle = max(maxEle, nums[i]);
  }
  return maxEle;
}

int linearSearch(vector<int> &nums, int target)
{
  // your code goes here
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums.push_back(data);
  }
  int target;
  cin >> target;
  // cout << linearSearch(nums, target);
  rotateArray(nums, target);
  for (int num : nums)
  {
    cout << num << " ";
  }
}