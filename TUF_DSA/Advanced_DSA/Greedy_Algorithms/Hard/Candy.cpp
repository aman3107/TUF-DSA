#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
  int sum = 1;
  int i = 1;
  int n = ratings.size();
  while (i < n)
  {
    if (ratings[i] == ratings[i - 1])
    {
      sum = sum + 1;
      i++;
      continue;
    }
    int peak = 1;
    while (i < n && ratings[i] > ratings[i - 1])
    {
      peak++;
      sum = sum + peak;
      i++;
    }
    int down = 1;
    while (i < n && ratings[i] < ratings[i - 1])
    {
      sum = sum + down;
      down++;
      i++;
    }
    if (down > peak)
    {
      sum = sum + (down - peak);
    }
  }
  return sum;
}

int candyBetter(vector<int> &ratings)
{
  // your code goes here
  int n = ratings.size();
  vector<int> left(n, 1);
  for (int i = 1; i < n; i++)
  {
    if (ratings[i] > ratings[i - 1])
    {
      left[i] = left[i - 1] + 1;
    }
  }
  int curr = 1;
  int right = 1;
  int ans = max(1, left[n - 1]);
  for (int i = n - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
    {
      curr = right + 1;
    }
    else
    {
      curr = 1;
    }
    right = curr;
    ans += max(left[i], right);
  }
  return ans;
}

int candyBrute(vector<int> &ratings)
{
  // your code goes here
  int n = ratings.size();
  vector<int> left(n, 1);
  vector<int> right(n, 1);
  for (int i = 1; i < n; i++)
  {
    if (ratings[i] > ratings[i - 1])
    {
      left[i] = left[i - 1] + 1;
    }
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
    {
      right[i] = right[i + 1] + 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += max(left[i], right[i]);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> ratings;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    ratings.push_back(data);
  }

  cout << candy(ratings) << endl;
}