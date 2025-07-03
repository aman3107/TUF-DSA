#include <bits/stdc++.h>
using namespace std;

int ninjaTrainingSpace(vector<vector<int>> &nums)
{
  int n = nums.size();
  vector<int> dp(4, 0);
  dp[0] = max(nums[0][1], nums[0][2]);
  dp[1] = max(nums[0][0], nums[0][2]);
  dp[2] = max(nums[0][0], nums[0][1]);
  dp[3] = max(nums[0][0], max(nums[0][1], nums[0][2]));
  for (int day = 1; day < n; day++)
  {
    vector<int> temp(4, 0);
    for (int lastTask = 0; lastTask < 4; lastTask++)
    {
      int maxi = 0;
      for (int i = 0; i < 3; i++)
      {
        if (i != lastTask)
        {
          int points = nums[day][i] + dp[i];
          maxi = max(maxi, points);
        }
      }
      temp[lastTask] = maxi;
    }
    dp = temp;
  }
  return dp[3];
}

int ninjaTrainingTabu(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  vector<vector<int>> dp(n, vector<int>(4, 0));
  dp[0][0] = max(matrix[0][1], matrix[0][2]);
  dp[0][1] = max(matrix[0][0], matrix[0][2]);
  dp[0][2] = max(matrix[0][0], matrix[0][1]);
  dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

  for (int day = 1; day < n; day++)
  {
    for (int lastTask = 0; lastTask < 4; lastTask++)
    {
      int maxi = 0;
      for (int i = 0; i < 3; i++)
      {
        if (i != lastTask)
        {
          int points = matrix[day][i] + dp[day - 1][i];
          maxi = max(maxi, points);
        }
      }
      dp[day][lastTask] = maxi;
    }
  }
  return dp[n - 1][3];
}

int memoHelper(int day, int lastTask, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
      if (i != lastTask)
      {
        maxi = max(maxi, matrix[day][i]);
      }
    }
    return maxi;
  }

  if (dp[day][lastTask] != -1)
  {
    return dp[day][lastTask];
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++)
  {
    if (i != lastTask)
    {
      int points = matrix[day][i] + memoHelper(day - 1, i, matrix, dp);
      maxi = max(maxi, points);
    }
  }
  return dp[day][lastTask] = maxi;
}

int ninjaTrainingMemo(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return memoHelper(n - 1, 3, matrix, dp);
}

int helper(int day, int lastTask, vector<vector<int>> &matrix)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
      if (i != lastTask)
      {
        maxi = max(maxi, matrix[day][i]);
      }
    }
    return maxi;
  }
  int maxi = 0;
  for (int i = 0; i <= 2; i++)
  {
    if (i != lastTask)
    {
      int points = matrix[day][i] + helper(day - 1, i, matrix);
      maxi = max(maxi, points);
    }
  }
  return maxi;
}

int ninjaTraining(vector<vector<int>> &matrix)
{
  return helper(matrix.size() - 1, 3, matrix);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> days;
  for (int i = 0; i < n; i++)
  {
    int task1, task2, task3;
    cin >> task1 >> task2 >> task3;
    days.push_back({task1, task2, task3});
  }
  cout << ninjaTrainingTabu(days) << endl;
  cout << ninjaTrainingMemo(days) << endl;
  cout << ninjaTraining(days) << endl;
}