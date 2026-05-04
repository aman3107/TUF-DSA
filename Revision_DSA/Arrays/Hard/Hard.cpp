#include <bits/stdc++.h>
using namespace std;

long long int merge(vector<int> &nums, int l, int mid, int r)
{
  int left = l;
  int right = mid + 1;
  vector<int> temp;
  long long int cnt = 0;
  while (left <= mid && right <= r)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left]);
      left++;
    }
    else
    {
      temp.push_back(nums[right]);
      cnt += (mid - left + 1);
      right++;
    }
  }

  while (left <= mid)
  {
    temp.push_back(nums[left]);
    left++;
  }
  while (right <= r)
  {
    temp.push_back(nums[right]);
    right++;
  }

  for (int i = l; i <= r; i++)
  {
    nums[i] = temp[i - l];
  }
  return cnt;
}

long long int mergeSort(vector<int> &nums, int l, int r)
{
  long long int cnt = 0;
  if (l < r)
  {
    int mid = (l + r) / 2;
    cnt += mergeSort(nums, l, mid);
    cnt += mergeSort(nums, mid + 1, r);
    cnt += merge(nums, l, mid, r);
  }
  return cnt;
}

long long int numberOfInversions(vector<int> nums)
{
  int n = nums.size();

  return mergeSort(nums, 0, n - 1);
}

vector<int> findMissingRepeatingNumbersBetter(vector<int> nums)
{
  int n = nums.size();
  int sum = n * (n + 1) / 2;
  unordered_map<int, int> mpp;
  int a = -1;
  int b = -1;
  for (int num : nums)
  {
    mpp[num]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (mpp[i] == 2)
    {
      a = i;
    }
    else if (mpp[i] == 0)
    {
      b = i;
    }

    if (a != -1 && b != -1)
      break;
  }
  return {a, b};
}

vector<int> majorityElementTwoOptimal(vector<int> &nums)
{
  int n = nums.size();
  int cnt1 = 0;
  int cnt2 = 0;
  int ele1 = INT_MIN;
  int ele2 = INT_MIN;
  for (int num : nums)
  {
    if (cnt1 == 0 && num != ele2)
    {
      cnt1 = 1;
      ele1 = num;
    }
    else if (cnt2 == 0 && num != ele1)
    {
      cnt2 = 1;
      ele2 = num;
    }
    else if (ele1 == num)
    {
      cnt1++;
    }
    else if (ele2 == num)
    {
      cnt2++;
    }
    else
    {
      cnt1--;
      cnt2--;
    }
  }
  vector<int> ans;
  cnt1 = 0;
  cnt2 = 0;
  for (int num : nums)
  {
    if (ele1 == num)
      cnt1++;
    else if (ele2 == num)
      cnt2++;
  }
  int mini = (int)(n / 3) + 1;
  if (cnt1 >= mini)
    ans.push_back(ele1);
  if (cnt2 >= mini)
    ans.push_back(ele2);
  return ans;
}

vector<int> majorityElementTwoBetter(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
    if (mpp[nums[i]] == (n / 3) + 1)
    {
      ans.push_back(nums[i]);
    }
  }
  return ans;
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

  vector<int> ans = majorityElementTwoBetter(nums);
  for (int a : ans)
  {
    cout << a << " ";
  }
}