#include <bits/stdc++.h>
using namespace std;

/*
It can be seen that any element in the rth row is of the form:
curr = (prev * (r-i))/(i)
where prev is the previous element in the row and i is the index of the element in the row.

Using this formula, we can generate the rth row of Pascal's triangle in O(n) time complexity.

Approach:

Initialize the list with a size equal to the given row number.
Set the first element of the row to 1, as the first element in every row of Pascal's Triangle is always 1.
Iterate through the row to compute each value using the above formula.
Return the computed row as the final result.
Time and Space Complexity:
Time Complexity: O(r) — because you compute r elements.

Space Complexity: O(r) — for storing the result row.
*/

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

int main()
{
  int n;
  cin >> n;
  vector<int> ans = pascalTriangleII(n);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}