#include <bits/stdc++.h>
using namespace std;

int secondMostFrequentElement(vector<int> &nums)
{
  unordered_map<int, int> mpp;
  for (int num : nums)
  {
    mpp[num]++;
  }

  int maxFreq = INT_MIN;
  int secMaxFreq = INT_MIN;
  int minElement = INT_MAX;
  int secMinElement = INT_MAX;

  for (auto it : mpp)
  {
    if (it.second > maxFreq)
    {
      secMaxFreq = maxFreq;
      secMinElement = minElement;
      maxFreq = it.second;
      minElement = it.first;
    }
    else if (it.second == maxFreq)
    {
      minElement = min(minElement, it.first);
    }
    else if (it.second > secMaxFreq && it.second < maxFreq)
    {
      secMaxFreq = it.second;
      secMinElement = it.first;
    }
    else if (it.second == secMaxFreq)
    {
      secMinElement = min(it.first, secMinElement);
    }
  }
  return secMinElement == INT_MAX ? -1 : secMinElement;
}

int mostFrequentElement(vector<int> &nums)
{
  unordered_map<int, int> mpp;
  for (int num : nums)
  {
    mpp[num]++;
  }

  int minElement = INT_MAX;
  int maxFreq = INT_MIN;
  for (auto it : mpp)
  {
    if (it.second > maxFreq)
    {
      maxFreq = it.second;
      minElement = it.first;
    }
    else if (it.second == maxFreq)
    {
      minElement = min(minElement, it.first);
    }
  }
  return minElement;
}

void countArrayChar(vector<char> &ch)
{
  int hash[26] = {0};
  for (char c : ch)
  {
    hash[c - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (hash[i] > 0)
      cout << hash[i] << " ";
  }
}

void countArrayNum(vector<int> &nums)
{
  int maxi = INT_MIN;
  for (int num : nums)
  {
    maxi = max(maxi, num);
  }

  vector<int> hash(maxi + 1, 0);
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  for (int h : hash)
  {
    cout << h << " ";
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
  cout << mostFrequentElement(nums);

  // vector<char> ch;
  // for (int i = 0; i < n; i++)
  // {
  //   char c;
  //   cin >> c;
  //   ch.push_back(c);
  // }

  // countArrayChar(ch);
}