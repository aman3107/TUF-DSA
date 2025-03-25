#include <bits/stdc++.h>
using namespace std;

int secondMostFrequentElement(vector<int> &nums)
{
  unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  int maxElement = -1;
  int maxFreq = -1;
  int secondMaxElement = -1;
  int secondMaxFreq = -1;
  for (auto it : hash)
  {
    int element = it.first;
    int frequency = it.second;
    if (frequency > maxFreq)
    {
      secondMaxElement = maxElement;
      secondMaxFreq = maxFreq;
      maxElement = element;
      maxFreq = frequency;
    }
    else if (frequency == maxFreq)
    {
      maxElement = min(element, maxElement);
    }
    else if (frequency > secondMaxFreq)
    {
      secondMaxElement = element;
      secondMaxFreq = frequency;
    }
    else if (frequency == secondMaxFreq)
    {
      secondMaxElement = min(element, secondMaxElement);
    }
  }
  return secondMaxElement;
}

int mostFrequentElement2(vector<int> &nums)
{
  int maxNum = nums[0];
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > maxNum)
    {
      maxNum = nums[i];
    }
  }
  int hash[maxNum + 1] = {0};
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  int maxElement = 0;
  int maxFreq = -1;
  for (int i = 0; i <= maxNum; i++)
  {
    if (hash[i] > maxFreq)
    {
      maxElement = i;
      maxFreq = hash[i];
    }
    else if (hash[i] == maxFreq)
    {
      maxElement = min(i, maxElement);
    }
  }
  return maxElement;

  // TC = O(n);
  // SC = O(maxElement)
}

int mostFrequentElement(vector<int> &nums)
{
  unordered_map<int, int> hash;
  int maxElement = 0;
  int maxFreq = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  for (auto it : hash)
  {
    int ele = it.first;
    int freq = it.second;

    if (freq > maxFreq)
    {
      maxElement = ele;
      maxFreq = freq;
    }

    if (freq == maxFreq)
    {
      maxElement = min(maxElement, ele);
    }
  }
  return maxElement;
  // TC =  O(n)
  // SC = O(n)
}

int minFrequentElement(vector<int> &nums)
{
  unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  int minElement = 0;
  int minFreq = INT_MAX;
  for (auto it : hash)
  {
    int element = it.first;
    int frequency = it.second;
    if (frequency < minFreq)
    {
      minElement = element;
      minFreq = frequency;
    }
    else if (frequency == minFreq)
    {
      minElement = min(minElement, element);
    }
  }
  return minElement;
}

int sumHighestAndLowestFrequency(vector<int> &nums)
{
  unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); i++)
  {
    hash[nums[i]]++;
  }
  int minFreq = INT_MAX;
  int maxFreq = INT_MIN;
  for (auto it : hash)
  {
    int frequency = it.second;
    minFreq = min(frequency, minFreq);
    maxFreq = max(frequency, maxFreq);
  }
  return minFreq + maxFreq;

  // TC = O(n)
  // SC = O(n)
}

int main()
{
  vector<int> vect;
  int n;
  cout << "Enter elements in the array :" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    vect.push_back(num);
  }

  // cout << mostFrequentElement(vect) << endl;
  // cout << mostFrequentElement2(vect) << endl;
  // cout << secondMostFrequentElement(vect) << endl;
  // cout << minFrequentElement(vect) << endl;
  cout << sumHighestAndLowestFrequency(vect) << endl;
}