#include <bits/stdc++.h>
using namespace std;

int sumHighestAndLowestFrequency(vector<int> &nums)
{
  int maxFreq = INT_MIN;
  int minFreq = INT_MAX;
  unordered_map<int, int> mpp;
  for (int num : nums)
  {
    mpp[num]++;
  }
  for (auto it : mpp)
  {
    int freq = it.second;
    maxFreq = max(freq, maxFreq);
    minFreq = min(freq, minFreq);
  }
  return maxFreq + minFreq;
}

int secondMostFrequentElement(vector<int> &nums)
{
  int maxEle = -1, secMaxEle = -1;
  int maxFreq = 0, secMaxFreq = 0;
  unordered_map<int, int> mpp;
  for (int x : nums)
  {
    mpp[x]++;
  }
  for (auto it : mpp)
  {
    int ele = it.first;
    int freq = it.second;
    if (freq > maxFreq)
    {
      secMaxEle = maxEle;
      maxEle = ele;
      secMaxFreq = maxFreq;
      maxFreq = freq;
    }
    else if (freq == maxFreq)
    {
      maxEle = min(maxEle, ele);
    }
    else if (freq > secMaxFreq)
    {
      secMaxEle = ele;
      secMaxFreq = freq;
    }
    else if (freq == secMaxFreq)
    {
      secMaxEle = min(secMaxEle, ele);
    }
  }
  return secMaxEle;
}

int mostFrequentElement(vector<int> &nums)
{
  int maxFreq = 0;
  int maxEle = -1;
  unordered_map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]]++;
  }
  for (auto it : mpp)
  {
    int ele = it.first;
    int freq = it.second;
    if (freq > maxFreq)
    {
      maxEle = ele;
      maxFreq = freq;
    }
    else if (freq == maxFreq)
    {
      maxEle = min(maxEle, ele);
    }
  }
  return maxEle;
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
  cout << sumHighestAndLowestFrequency(nums);
}