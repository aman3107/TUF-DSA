#include <bits/stdc++.h>
using namespace std;

// When index needs to returned
vector<int> maxSubArray1(vector<int> &nums)
{
  int maxi = INT_MIN;     // Stores max subarray sum found
  int sum = 0;            // Current subarray sum
  int start = 0, end = 0; // Indices of the best subarray
  int tempStart = 0;      // Potential new start index when resetting sum

  for (int i = 0; i < nums.size(); i++)
  {
    if (sum < 0)
    {
      sum = 0;       // Reset if sum is negative
      tempStart = i; // Mark potential new start
    }
    sum += nums[i]; // Add current element to sum

    if (sum > maxi)
    {
      maxi = sum;        // New maximum found
      start = tempStart; // Update final start
      end = i;           // Update final end
    }
  }
  return {start, end}; // Return the indices of the max subarray
}

// When only sum is returned
int maxSubArray(vector<int> &nums)
{
  int maxi = INT_MIN; // Keeps track of the maximum sum so far
  int sum = 0;        // Current running subarray sum
  for (int i = 0; i < nums.size(); i++)
  {
    if (sum < 0)
    {
      sum = 0; // Reset the subarray if the sum goes negative
    }
    sum = sum + nums[i];   // Add the current element to the running sum
    maxi = max(maxi, sum); // Return the highest sum found
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  cout << maxSubArray(arr) << endl;
}