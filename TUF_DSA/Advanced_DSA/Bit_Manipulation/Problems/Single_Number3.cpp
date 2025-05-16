#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber3(vector<int> &nums)
{
  vector<int> ans;
  int XOR = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    XOR = XOR ^ nums[i];
  }

  int rightMost = (XOR & (XOR - 1)) ^ XOR;
  int XOR1 = 0, XOR2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (rightMost & nums[i])
    {
      XOR1 = XOR1 ^ nums[i];
    }
    else
    {
      XOR2 = XOR2 ^ nums[i];
    }
  }
  ans.push_back(XOR1);
  ans.push_back(XOR2);
  sort(ans.begin(), ans.end());
  return ans;
}

vector<int> singleNumber3Brute(vector<int> &nums)
{
  // your code goes here
  unordered_map<int, int> ump;
  for (int i = 0; i < nums.size(); i++)
  {
    ump[nums[i]]++;
  }
  vector<int> ans;
  for (auto it : ump)
  {
    if (it.second == 1)
    {
      ans.push_back(it.first);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    v.push_back(data);
  }
  vector<int> ans = singleNumber3(v);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}