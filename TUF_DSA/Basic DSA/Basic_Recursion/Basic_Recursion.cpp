#include <bits/stdc++.h>
using namespace std;

int arraySumHelper(vector<int> &nums, int ind)
{
  // your code goes here
  if (ind == nums.size())
  {
    return 0;
  }
  return nums[ind] + arraySumHelper(nums, ind + 1);
}

int arraySum(vector<int> &nums)
{
  // your code goes here
  if (nums.size() == 0)
  {
    return 0;
  }
  return arraySumHelper(nums, 0);

  // TC = O(n)
  // SC = O(n)
}

int addDigits(int num)
{
  // your code goes here
  if (num <= 9)
  {
    return num;
  }
  int sum = 0;
  while (num > 0)
  {
    int lastDigit = num % 10;
    sum = sum + lastDigit;
    num = num / 10;
  }
  return addDigits(sum);
}

vector<char> reverseStringHelper(vector<char> &s, int left, int right)
{
  if (left >= right)
  {
    return s;
  }
  char temp = s[left];
  s[left] = s[right];
  s[right] = temp;
  return reverseStringHelper(s, left + 1, right - 1);
}

vector<char> reverseString(vector<char> &s)
{
  // your code goes here
  if (s.size() == 0 || s.size() == 1)
  {
    return s;
  }
  return reverseStringHelper(s, 0, s.size() - 1);

  // TC = O(n)
  // SC = O(n)
}

bool palindromeCheckHelper(string &s, int left, int right)
{
  if (left >= right)
  {
    return true;
  }
  if (s[left] != s[right])
  {
    return false;
  }
  return palindromeCheckHelper(s, left + 1, right - 1);
}

bool palindromeCheck(string &s)
{
  // your code goes here
  if (s.size() == 0 && s.size() == 1)
  {
    return true;
  }
  return palindromeCheckHelper(s, 0, s.size() - 1);
}

bool checkPrimeHelper(int num, int div)
{
  if (div > sqrt(num))
  {
    return true;
  }
  if (num % div == 0)
  {
    return false;
  }
  return checkPrimeHelper(num, div + 1);
}

bool checkPrime(int num)
{
  // your code goes here
  return checkPrimeHelper(num, 2);

  // TC = O(sqrt(n))
  // SC = O(sqrt(n))
}

void reverseArrayHelper(vector<int> &nums, int left, int right)
{
  if (left > right)
  {
    return;
  }
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
  reverseArrayHelper(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int> &nums)
{
  // your code goes here
  reverseArrayHelper(nums, 0, nums.size() - 1);
  return nums;

  // TC = O(n)
  // SC = O(n)
}

bool isSortedHelper(vector<int> &nums, int i, int j)
{
  if (j == nums.size())
  {
    return true;
  }
  if (nums[i] > nums[j])
  {
    return false;
  }
  return isSortedHelper(nums, i + 1, j + 1);
}

bool isSorted(vector<int> &nums)
{
  // your code goes here
  if (nums.size() <= 1)
  {
    return true;
  }
  return isSortedHelper(nums, 0, 1);

  // TC =  O(n)
  // SC = O(n)
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }
  // reverseArray(v);
  cout << isSorted(v) << endl;
  for (auto a : v)
  {
    cout << a << " ";
  }
  cout << endl;
  /*

  int num;
  cin >> num;
  cout << checkPrime(num) << endl;

  string s;
  cin >> s;
  cout << palindromeCheck(s) << endl;

  vector<char> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char ch;
    cin >> ch;
    s.push_back(ch);
  }

  vector<char> ans = reverseString(s);
  for (auto a : ans)
  {
    cout << a << "  ";
  }
  cout << endl;


  int num;
  cin >> num;
  cout << addDigits(num) << endl;

  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    v.push_back(num);
  }
  cout << arraySum(v) << endl;
  */
}