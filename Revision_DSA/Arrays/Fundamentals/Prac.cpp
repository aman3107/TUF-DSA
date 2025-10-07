#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int l, int r)
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
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
  reverse(nums, 0, n - 1);
}

void rotateArrayByOne(vector<int> &nums)
{
  int num = nums[0];
  int n = nums.size();
  for (int i = 1; i < n; i++)
  {
    nums[i - 1] = nums[i];
  }
  nums[n - 1] = num;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int count = 0;
  int maxi = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      count++;
      maxi = max(maxi, count);
    }
    else
    {
      count = 0;
    }
  }
  return maxi;
}

int secondLargestElement(vector<int> &nums)
{
  // your code goes here
  int maxi = INT_MIN;
  int maxi2 = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > maxi)
    {
      maxi2 = maxi;
      maxi = nums[i];
    }
    else if (nums[i] > maxi2 && nums[i] < maxi)
    {
      maxi2 = nums[i];
    }
  }
  return maxi2 == INT_MIN ? -1 : maxi2;
}

int largestElement(vector<int> &nums)
{
  int maxi = nums[0];
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] > maxi)
    {
      maxi = nums[i];
    }
  }
  return maxi;
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
}