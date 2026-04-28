#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
  // Your code goes here

  int ind = -1;
  int n = nums.size();
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      ind = i;
      break;
    }
  }

  if (ind == -1)
  {
    reverse(nums.begin(), nums.end());
    return;
  }
  else
  {

    for (int i = n - 1; i > ind; i--)
    {
      if (nums[i] > nums[ind])
      {
        swap(nums[ind], nums[i]);
        break;
      }
    }

    reverse(nums.begin() + ind + 1, nums.end());
    return;
  }
}

int maxSubArray(vector<int> &nums)
{
  int maxi = INT_MIN;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (sum < 0)
    {
      sum = 0;
    }
    sum += nums[i];
    maxi = max(maxi, sum);
  }
  return maxi;
}

void sortZeroOneTwo(vector<int> &nums)
{
  int low = 0;
  int mid = 0;
  int high = nums.size() - 1;
  while (mid <= high)
  {
    if (nums[mid] == 0)
    {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }
    else if (nums[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(nums[mid], nums[high]);
      high--;
    }
  }
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n - 3; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n - 2; j++)
    {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;
      int l = j + 1;
      int r = n - 1;
      while (l < r)
      {
        int sum = nums[i] + nums[j] + nums[l] + nums[r];
        if (sum == target)
        {
          ans.push_back({nums[i], nums[j], nums[l], nums[r]});
          l++;
          r--;
          while (l < r && nums[l] == nums[l - 1])
          {
            l++;
          }
          while (l < r && nums[r] == nums[r + 1])
          {
            r--;
          }
        }
        else if (sum < target)
          l++;
        else
          r--;
      }
    }
  }
  return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n - 2; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int l = i + 1;
    int r = n - 1;
    while (l < r)
    {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum == 0)
      {
        ans.push_back({nums[i], nums[l], nums[r]});
        l++;
        r--;
        while (l < r && nums[l] == nums[l - 1])
        {
          l++;
        }
        while (l < r && nums[r] == nums[r + 1])
        {
          r--;
        }
      }
      else if (sum < 0)
      {
        l++;
      }
      else
      {
        r--;
      }
    }
  }
  return ans;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
  return a.first < b.first;
}

vector<int> twoSumOptimal(vector<int> &nums, int target)
{
  vector<pair<int, int>> temp;
  for (int i = 0; i < nums.size(); i++)
  {
    temp.push_back({nums[i], i});
  }

  sort(temp.begin(), temp.end(), compare);

  int l = 0;
  int r = nums.size() - 1;
  while (l < r)
  {
    int sum = temp[l].first + temp[r].first;
    if (sum == target)
    {

      return {temp[l].second, temp[r].second};
    }
    else if (sum < target)
    {
      l++;
    }
    else
    {
      r--;
    }
  }
  return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &nums, int target)
{
  unordered_map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    int num = nums[i];
    int needed = target - num;
    if (mpp.find(needed) != mpp.end())
    {
      return {mpp[needed], i};
    }
    mpp[num] = i;
  }
  return {-1, -1};
}

void rotateMatrix(vector<vector<int>> &matrix)
{
  int n = matrix[0].size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

vector<vector<int>> pascalTriangleIII(int n)
{
  vector<vector<int>> ans;
  for (int r = 1; r <= n; r++)
  {
    long long res = 1;
    vector<int> temp;
    temp.push_back(1);
    for (int i = 1; i < r; i++)
    {
      res = res * (r - i);
      res = res / i;
      temp.push_back(res);
    }
    ans.push_back(temp);
  }
  return ans;
}

vector<int> pascalTriangleII(int r)
{
  int res = 1;
  vector<int> ans;
  ans.push_back(1);
  for (int i = 1; i < r; i++)
  {
    res = res * (r - i);
    res = res / (i);
    ans.push_back(res);
  }
  return ans;
}

int pascalTriangleI(int r, int c)
{
  long long res = 1;
  r = r - 1;
  c = c - 1;
  for (int i = 0; i < c; i++)
  {
    res = res * (r - i);
    res = res / (i + 1);
  }
  return res;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();
  int sr = 0;
  int sc = 0;
  int er = m - 1;
  int ec = n - 1;
  vector<int> ans;
  while (sr <= er && sc <= ec)
  {
    for (int i = sc; i <= ec; i++)
    {
      ans.push_back(matrix[sr][i]);
    }
    sr++;
    for (int i = sr; i <= er; i++)
    {
      ans.push_back(matrix[i][ec]);
    }
    ec--;
    if (sr <= er)
    {
      for (int i = ec; i >= sc; i--)
      {
        ans.push_back(matrix[er][i]);
      }
      er--;
    }
    if (sc <= ec)
    {
      for (int i = er; i >= sr; i--)
      {
        ans.push_back(matrix[i][sc]);
      }
      sc++;
    }
  }
  return ans;
}

vector<int> rearrangeArray(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, 0);
  int pos = 0;
  int neg = 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= 0)
    {
      ans[pos] = nums[i];
      pos += 2;
    }
    else
    {
      ans[neg] = nums[i];
      neg += 2;
    }
  }
  return ans;
}

vector<int> leaders(vector<int> &nums)
{
  int n = nums.size() - 1;
  vector<int> ans;
  int leader = nums[n];
  ans.push_back(leader);
  n--;
  while (n >= 0)
  {
    if (nums[n] > leader)
    {
      ans.push_back(nums[n]);
      leader = nums[n];
    }
    n--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int majorityElement(vector<int> &nums)
{
  int cnt = 0;
  int ele;
  for (int num : nums)
  {
    if (cnt == 0)
    {
      ele = num;
      cnt++;
    }
    else if (ele == num)
    {
      cnt++;
    }
    else
    {
      cnt--;
    }
  }
  return ele;
}

int main()
{
  // int n;
  // cin >> n;
  // vector<int> nums;
  // for (int i = 0; i < n; i++)
  // {
  //   int data;
  //   cin >> data;
  //   nums.push_back(data);
  // }

  // vector<int> ans = leaders(nums);
  // for (int a : ans)
  // {
  //   cout << a << " ";
  // }

  int r, c;
  cin >> r;
  cin >> c;
  cout << pascalTriangleI(r, c);
}