#include <bits/stdc++.h>
using namespace std;

int addHelper(int num)
{
  if (num == 0)
    return 0;
  return num % 10 + addHelper(num / 10);
}

int addDigits(int num)
{
  // your code goes here
  if (num < 10)
  {
    return num;
  }

  int sum = addHelper(num);
  return addDigits(sum);
}

bool sortedHelper(vector<int> &nums, int n)
{
  if (n == nums.size())
  {
    return true;
  }
  if (nums[n - 1] > nums[n])
    return false;

  return sortedHelper(nums, n + 1);
}

bool isSorted(vector<int> &nums)
{
  // your code goes here
  if (nums.size() <= 1)
    return true;
  return sortedHelper(nums, 1);
}

void reverseArrayHelper(vector<int> &nums, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int temp = nums[l];
  nums[l] = nums[r];
  nums[r] = temp;
  reverseArrayHelper(nums, l + 1, r - 1);
}

vector<int> reverseArray(vector<int> &nums)
{
  // your code goes here
  reverseArrayHelper(nums, 0, nums.size() - 1);
  return nums;
}

bool primeHelper(int num, int d)
{
  if (d * d > num)
    return true;

  if (num % d == 0)
    return false;
  return primeHelper(num, d + 1);
}

bool checkPrime(int num)
{
  // your code goes here
  if (num <= 1)
    return false;
  return primeHelper(num, 2);
}

bool palindromeHelper(string &s, int l, int r)
{
  if (l >= r)
    return true;
  if (s[l] != s[r])
    return false;

  return palindromeHelper(s, l + 1, r - 1);
}

bool palindromeCheck(string &s)
{
  // your code goes here
  return palindromeHelper(s, 0, s.size() - 1);
}

void reverseHelper(vector<char> &s, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  char temp = s[l];
  s[l] = s[r];
  s[r] = temp;
  reverseHelper(s, l + 1, r - 1);
}

vector<char> reverseString(vector<char> &s)
{
  // your code goes here
  reverseHelper(s, 0, s.size() - 1);
  return s;
}

int helper(vector<int> &nums, int n)
{
  if (n < 0)
  {
    return 0;
  }
  return nums[n] + helper(nums, n - 1);
}

int arraySum(vector<int> &nums)
{
  // your code goes here
  return helper(nums, nums.size() - 1);
}

long long int factorial(int n)
{
  // your code goes here
  if (n == 0)
  {
    return 1;
  }

  return n * factorial(n - 1);
}

int NnumbersSum(int N)
{
  // your code goes here
  if (N == 0)
  {
    return 0;
  }
  return N + NnumbersSum(N - 1);
}

int main()
{
  int n;
  cin >> n;
  // cout << factorial(n) << endl;
  // vector<int> nums;
  // for (int i = 0; i < n; i++)
  // {
  //   int data;
  //   cin >> data;
  //   nums.push_back(data);
  // }
  // vector<char> ans = reverseString(nums);
  // for (auto it : ans)
  // {
  //   cout << it << " ";
  // }

  // string s;
  // cin >> s;
  // vector<int> ans = reverseArray(nums);
  // for (auto it : ans)
  //   cout << it << " ";
  cout << addDigits(n) << "\n";
}