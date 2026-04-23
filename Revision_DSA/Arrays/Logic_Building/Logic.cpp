#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n && j < m)
  {
    if (nums1[i] == nums2[j])
    {
      ans.push_back(nums1[i]);
      i++;
      j++;
    }
    else
    {
      if (nums1[i] < nums2[j])
      {
        i++;
      }
      else
      {
        j++;
      }
    }
  }
  return ans;
}

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> ans;

  while (i < n && j < m)
  {
    if (nums1[i] <= nums2[j])
    {
      if (ans.size() == 0 || nums1[i] != ans.back())
        ans.push_back(nums1[i]);
      i++;
    }
    else if (nums2[j] < nums1[i])
    {
      if (ans.size() == 0 || nums2[j] != ans.back())
        ans.push_back(nums2[j]);
      j++;
    }
  }
  while (i < n)
  {
    if (nums1[i] != ans.back())
    {
      ans.push_back(nums1[i]);
    }
    i++;
  }

  while (j < m)
  {
    if (nums2[j] != ans.back())
    {
      ans.push_back(nums2[j]);
    }
    j++;
  }
  return ans;
}

int missingNumber(vector<int> &nums)
{
  int n = nums.size();
  int totalSum = (n * (n + 1)) / 2;
  for (int i = 0; i < n; i++)
  {
    totalSum -= nums[i];
  }
  return totalSum;
}

int removeDuplicates(vector<int> &nums)
{
  int i = 0;
  for (int j = 1; j < nums.size(); j++)
  {
    if (nums[i] != nums[j])
    {
      i++;
      nums[i] = nums[j];
    }
  }
  return i;
}

void moveZeroes(vector<int> &nums)
{
  int j = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    // Whenever it encounter non zero swap and the place the j in next non zero number index
    if (nums[i] != 0)
    {
      swap(nums[i], nums[j]);
      j++;
    }
  }
}

int main()
{
  int n, m;
  cin >> n;
  cin >> m;
  vector<int> nums1;
  vector<int> nums2;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    nums1.push_back(data);
  }

  for (int i = 0; i < m; i++)
  {
    int data;
    cin >> data;
    nums2.push_back(data);
  }
  vector<int> nums = intersectionArray(nums1, nums2);
  for (int num : nums)
  {
    cout << num << " ";
  }
}