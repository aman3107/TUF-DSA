#include <bits/stdc++.h>
using namespace std;

/*
✅ Intuition
  The Count and Say problem is about generating a specific pattern based on how the previous string looks.
  The rule is simple:
  "Say what you see" — for each group of consecutive same digits, say how many followed by what digit.

  Example:
  If the string is "1211", you read it as:
  One '1' → "11"
  One '2' → "12"
  Two '1's → "21"
  So the result is "111221"
  This pattern builds on itself, starting from "1" and applying the rule n times to reach the nth term.

🔍 Approach (Recursive)
Base Case:
If n == 1, return "1" as the first term of the sequence.

Recursive Step:
Call countAndSay(n - 1) to get the previous term in the sequence.
Process the Previous Term:
Initialize an empty result string res and a count cnt = 1.
Loop from i = 1 to the end of the string:
If the current character is the same as the previous, increment the count.
If not, append cnt + previous character to res and reset cnt = 1.

Post-Loop Handling:

After the loop ends, append the last group of characters using:
res += to_string(cnt) + prev[i - 1];
Return the Result:
Return the newly formed res string which represents the nth term.

💡 Example Dry Run for n = 5
Let's trace countAndSay(5):
countAndSay(4) → "1211"
Process "1211":
'1' → one '1' → "11"
'2' → one '2' → "12"
'1', '1' → two '1's → "21"
Final result: "111221"

🧠 Time & Space Complexity
Time: O(2^n) → each term roughly doubles in size.

Space: O(2^n) → due to recursion + result string.


*/

string countAndSay(int n)
{
  if (n == 1)
  {
    return "1";
  }

  string ans = countAndSay(n - 1);
  int cnt = 1;
  string res = "";
  int i = 1;

  while (i < ans.size())
  {
    if (ans[i] == ans[i - 1])
    {
      cnt++;
      i++;
    }
    else
    {
      res += to_string(cnt) + ans[i - 1];
      cnt = 1;
      i++;
    }
  }
  res += to_string(cnt) + ans[i - 1];

  return res;
}

int main()
{
  int n;
  cin >> n;
  cout << countAndSay(n) << endl;
}