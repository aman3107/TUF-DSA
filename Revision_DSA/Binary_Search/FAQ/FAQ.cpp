#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistanceBetter(vector<int> &arr, int k)
{
  int n = arr.size();
  priority_queue<pair<long double, int>> pq;
  vector<int> howMany(n - 1, 0);
  for (int i = 0; i < n - 1; i++)
  {
    int diffLen = arr[i + 1] - arr[i];
    pq.push({diffLen, i});
  }

  for (int gas = 1; gas <= k; gas++)
  {
    auto tp = pq.top();
    pq.pop();
    int maxInd = tp.second;
    howMany[maxInd]++;
    int diffLen = arr[maxInd + 1] - arr[maxInd];
    long double secLen = (long double)diffLen / (howMany[maxInd] + 1);
    pq.push({secLen, maxInd});
  }
  return pq.top().first;
}

long double minimiseMaxDistanceBrute(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> temp(n - 1, 0);
  for (int i = 1; i <= k; i++)
  {
    long double maxLen = -1;
    int maxInd = -1;
    for (int i = 0; i < n - 1; i++)
    {

      int diffLength = arr[i + 1] - arr[i];
      long double secLen = (long double)diffLength / (temp[i] + 1);
      if (maxLen < secLen)
      {
        maxLen = secLen;
        maxInd = i;
      }
    }
    temp[maxInd]++;
  }
  long double maxAns = -1;
  for (int i = 0; i < n - 1; i++)
  {

    int diffLength = arr[i + 1] - arr[i];
    long double secLen = (long double)diffLength / (temp[i] + 1);
    maxAns = max(maxAns, secLen);
  }
  return maxAns;
}

int kthElement(vector<int> &a, vector<int> &b, int k)
{
  int n1 = a.size();
  int n2 = b.size();
  if (n1 > n2)
    return kthElement(b, a, k);
  int left = k;
  int low = max(0, k - n2);
  int high = min(k, n1);

  while (low <= high)
  {
    int mid1 = low + (high - low) / 2;
    int mid2 = left - mid1;
    int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
    int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
    int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
    int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

    if (l1 <= r2 && l2 <= r1)
    {
      return max(l1, l2);
    }
    else if (l1 > r2)
    {
      high = mid1 - 1;
    }
    else
    {
      low = mid1 + 1;
    }
  }
  return 0;
}

double median(vector<int> &arr1, vector<int> &arr2)

{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int n = n1 + n2;
  if (n1 > n2)
    return median(arr2, arr1);
  int left = (n1 + n2 + 1) / 2;

  int low = 0;
  int high = n1;
  while (low <= high)
  {
    int mid1 = low + (high - low) / 2;
    int mid2 = left - mid1;
    int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
    int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
    int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
    int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;
    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 1)
        return max(l1, l2);
      else
        return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
    }
    else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
}

double medianBetter(vector<int> &arr1, vector<int> &arr2)

{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int n = n1 + n2;
  int ind2 = n / 2;
  int ind1 = ind2 - 1;
  int ele1 = 0;
  int ele2 = 0;
  int cnt = 0;
  int l = 0;
  int r = 0;
  while (l < n1 && r < n2)
  {
    if (arr1[l] <= arr2[r])
    {
      if (cnt == ind1)
      {
        ele1 = arr1[l];
      }
      if (cnt == ind2)
      {
        ele2 = arr1[l];
      }
      l++;
    }
    else
    {
      if (cnt == ind1)
      {
        ele1 = arr2[r];
      }
      if (cnt == ind2)
      {
        ele2 = arr2[r];
      }
      r++;
    }

    cnt++;
  }
  while (l < n1)
  {
    if (cnt == ind1)
    {
      ele1 = arr1[l];
    }
    if (cnt == ind2)
    {
      ele2 = arr1[l];
    }
    l++;
    cnt++;
  }

  while (r < n2)
  {
    if (cnt == ind1)
    {
      ele1 = arr2[r];
    }
    if (cnt == ind2)
    {
      ele2 = arr2[r];
    }
    r++;
    cnt++;
  }

  if (n % 2 == 0)
  {
    return (ele1 + ele2) / 2.0;
  }
  else
  {
    return ele2;
  }
}

double medianBrute(vector<int> &arr1, vector<int> &arr2)
{
  int n = arr1.size();
  int m = arr2.size();

  int l = 0;
  int r = 0;

  vector<int> temp;

  while (l < n && r < m)
  {
    if (arr1[l] <= arr2[r])
    {
      temp.push_back(arr1[l]);
      l++;
    }
    else
    {
      temp.push_back(arr2[r]);
      r++;
    }
  }
  while (l < n)
  {
    temp.push_back(arr1[l]);
    l++;
  }
  while (r < m)
  {
    temp.push_back(arr2[r]);
    r++;
  }

  int total = n + m;
  if (total % 2 != 0)
  {
    int ans = total / 2;
    return temp[ans];
  }
  else
  {
    int ans = total / 2;
    int ans2 = ans - 1;
    return (temp[ans] + temp[ans2]) / 2.0;
  }
}

int findPeakElement(vector<int> &arr)
{
  int n = arr.size();

  if (n == 1 || arr[0] > arr[1])
    return 0;
  if (arr[n - 1] > arr[n - 2])
    return n - 1;
  int low = 1;
  int high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
    {
      return mid;
    }
    else if (arr[mid - 1] < arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int pagesHelper(vector<int> &nums, int pages)
{
  int cntStudents = 1;
  int pagesStudent = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (pagesStudent + nums[i] <= pages)
    {
      pagesStudent += nums[i];
    }
    else
    {
      pagesStudent = nums[i];
      cntStudents++;
    }
  }
  return cntStudents;
}

int findPages(vector<int> &nums, int m)
{
  int n = nums.size();
  if (m > n)
    return -1;
  int low = INT_MIN;
  int high = 0;
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    high += nums[i];
    low = max(low, nums[i]);
  }
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int cntStudents = pagesHelper(nums, mid);
    if (cntStudents <= m)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int findPagesBrute(vector<int> &nums, int m)
{
  int n = nums.size();
  if (m > n)
    return -1;
  int sum = 0;
  int maxN = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    maxN = max(nums[i], maxN);
  }
  for (int i = maxN; i <= sum; i++)
  {
    int cntStudents = pagesHelper(nums, i);
    if (cntStudents == m)
      return i;
  }
}

bool helper(vector<int> &nums, int dist, int cows)
{
  int cntCows = 1;
  int last = nums[0];
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] - last >= dist)
    {
      last = nums[i];
      cntCows++;
    }
    if (cntCows >= cows)
      return true;
  }
  return false;
}

int aggressiveCows(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int low = 1;
  int high = nums[n - 1] - nums[0];
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (helper(nums, mid, k))
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int aggressiveCowsBrute(vector<int> &nums, int k)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int ans = 1;
  int limit = nums[n - 1] - nums[0];
  for (int i = 1; i <= limit; i++)
  {
    if (helper(nums, i, k))
    {
      continue;
    }
    else
    {
      return (i - 1);
    }
  }
  return limit;
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

  int k;
  cin >> k;
  cout << aggressiveCowsBrute(nums, k);
}