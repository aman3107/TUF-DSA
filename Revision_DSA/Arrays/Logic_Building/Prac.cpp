#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  int i = 0;
  int j = 0;
  vector<int> intersect;
  while (i < n1 && j < n2)
  {
    if (nums1[i] == nums2[j])
    {
      intersect.push_back(nums1[i]);
      i++;
      j++;
    }
    else if (nums1[i] < nums2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  return intersect;
}

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
  int i = 0;
  int j = 0;
  vector<int> nums3;
  int n1 = nums1.size();
  int n2 = nums2.size();
  while (i < n1 && j < n2)
  {
    if (nums1[i] <= nums2[j])
    {
      if (nums3.size() == 0 || nums3.back() != nums1[i])
      {
        nums3.push_back(nums1[i]);
        i++;
      }
    }
    else if (nums2[j] < nums1[i])
    {
      if (nums3.size() == 0 || nums3.back() != nums1[i])
      {
        nums3.push_back(nums2[j]);
        j++;
      }
    }
  }
  while (i < n1)
  {
    if (nums3.size() == 0 || nums3.back() != nums1[i])
    {
      nums3.push_back(nums1[i]);
      i++;
    }
  }
  while (j < n2)
  {
    if (nums3.size() == 0 || nums3.back() != nums1[i])
    {
      nums3.push_back(nums2[j]);
      j++;
    }
  }
  return nums3;
}

int missingNumber(vector<int> &nums)
{
  int n = nums.size();
  int total_sum = (n * (n + 1)) / 2;
  int sum = 0;
  for (auto &it : nums)
  {
    sum += it;
  }
  return total_sum - sum;
}

int removeDuplicates(vector<int> &nums)
{
  int count_unique = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i - 1] != nums[i])
    {
      count_unique++;
      nums[count_unique] = nums[i];
    }
  }
  return count_unique + 1;
}

void moveZeroes(vector<int> &nums)
{
  int j = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != 0)
    {
      swap(nums[i], nums[j]);
      j++;
    }
  }
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
  int m;
  cin >> m;
  vector<int> nums1;
  for (int i = 0; i < m; i++)
  {
    int data;
    cin >> data;
    nums1.push_back(data);
  }
  // moveZeroes(nums);
  // cout << removeDuplicates(nums);
  // cout << missingNumber(nums) << endl;
  // vector<int> ans = unionArray(nums, nums1);
  vector<int> ans = intersectionArray(nums, nums1);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}