#include <bits/stdc++.h>
using namespace std;

/*
💡 Intuition:
Given an array nums and a list of queries queries[i] = [x, m], you must return an array of answers where each answer is:
The maximum XOR of x with any number in nums that is ≤ m, or
-1 if no such number exists.

1. Maximizing XOR:
To maximize x ^ y, we want x and y to have opposite bits at the most significant positions.
For example:

x = 5 (0101)
y = 2 (0010)
5 ^ 2 = 7 (0111) → higher XOR because more differing bits.
So, to find the best number in nums for a given x, we want a number with as many opposite bits as possible at the highest positions.

2. Using a Trie (Prefix Tree):
A binary Trie is perfect for efficiently finding numbers that differ in bits:
Each node has 2 children: for bit 0 and bit 1.
We insert numbers into the trie bit-by-bit (32 bits for ints).
For a given number x, we walk through the trie preferring the opposite bit to get the max XOR.

3. Efficient Query Handling (Offline Queries):
Instead of answering each query independently (which is slow), we:
Sort the queries by m.
Sort the nums.
As we process queries in increasing m, we insert into the Trie only those numbers in nums that are ≤ m.
This is called the Offline Query Technique — process queries in a way that lets us reuse work already done.

🧠 Step-by-Step Approach:
🔹 Step 1: Sort nums
So we can insert only elements ≤ m for each query efficiently.

sort(nums.begin(), nums.end());
🔹 Step 2: Reformat queries (offline queries)
Each query is of the form [x, m]. We store them with m as the first value so we can sort by m.

vector<pair<int, pair<int, int>>> offline_Queries;
for (int i = 0; i < queries.size(); i++) {
  offline_Queries.push_back({queries[i][1], {queries[i][0], i}});
}
sort(offline_Queries.begin(), offline_Queries.end());
This gives us:
offline_Queries[i] = {m, {x, original_index}}

🔹 Step 3: Process Queries
Use i to track how many numbers from nums we've inserted into the Trie.
For each query (x, m):
Insert all nums[i] ≤ m into the Trie.
Use Trie to get the number that gives maximum XOR with x.

for (auto &it : offline_Queries)
{
  while (i < n && nums[i] <= it.first)
  {
    tr.insert(nums[i]);
    i++;
  }

  if (i != 0)
  {
    ans[it.second.second] = tr.getMax(it.second.first);
  }
  else
  {
    ans[it.second.second] = -1;
  }
}
🔹 Step 4: Return answers
ans array stores answers in the original query order, because we saved the original indices while storing offline queries.

🧩 Trie Details
Trie Structure:
class Node
{
  Node *links[2] = {nullptr};

  // Contains, get, put methods
};

class Trie
{
  Node *root;

  void insert(num)
  {
    // Insert 32-bit representation into trie
  }

  int getMax(num)
  {
    // Traverse trie to find number giving max XOR with num
  }
};
🧪 Example Walkthrough:
Input:
nums = [0,1,2,3,4]
queries = [[3,1],[1,3],[5,6]]
Sort nums: [0,1,2,3,4]

Offline queries after sorting by m:
[[3,1],[1,3],[5,6]] → becomes [(1, {3,0}), (3,{1,1}), (6,{5,2})]

Step-by-step:
Query 1: x=3, m=1
→ Only nums ≤ 1 = [0,1] inserted
→ Try to get max(3 ^ num) from [0,1]
→ Max = 3 ^ 0 = 3

Query 2: x=1, m=3
→ Insert 2 and 3
→ nums in trie = [0,1,2,3]
→ max = 1 ^ 2 = 3

Query 3: x=5, m=6
→ Insert 4
→ nums in trie = [0,1,2,3,4]
→ max = 5 ^ 2 = 7

Final answer: [3, 3, 7]

⏱️ Time Complexity:
Operation	Time
Sort nums	O(n log n)
Sort queries	O(q log q)
Trie insert/search per number	O(32) = O(1)
Total	O((n + q) log n)


*/

class Node
{
  Node *links[2] = {nullptr}; // Pointers for 0 and 1

public:
  bool containsKey(int bit)
  {
    return links[bit] != nullptr; // Checks if path for bit exists
  }

  Node *get(int bit)
  {
    return links[bit]; // Returns the child node at that bit
  }

  void put(int bit, Node *node)
  {
    links[bit] = node; // Sets the child node for a given bit
  }
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(int num)
  {
    Node *node = root;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1; // Extract i-th bit from left (MSB first)
      if (!node->containsKey(bit))
      {
        node->put(bit, new Node()); // Create path if not exists
      }
      node = node->get(bit); // Move to the next node
    }
  }

  int getMax(int num)
  {
    Node *node = root;
    int maxNum = 0;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1; // Extract i-th bit from left (MSB first)
      if (node->containsKey(1 - bit))
      {
        maxNum = maxNum | (1 << i); // Set the i-th bit in result to 1
        node = node->get(1 - bit);  // Go to the opposite bit for max XOR
      }
      else
      {
        node = node->get(bit); // Else go in the same direction
      }
    }
    return maxNum;
  }
};

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
  // your code goes here
  Trie tr;
  // Sort the array
  sort(nums.begin(), nums.end());
  // Create an offilne queries array with adding indices also
  vector<pair<int, pair<int, int>>> offline_Queries;
  int i = 0;
  for (auto &it : queries)
  {
    offline_Queries.push_back({it[1], {it[0], i}});
    i++;
  }
  // Sort the offline queries based on ai
  sort(offline_Queries.begin(), offline_Queries.end());
  int m = queries.size();
  vector<int> ans(m, 0);
  i = 0;
  int n = nums.size();
  for (auto &it : offline_Queries)
  {
    // If nums[i] <= ai. Insert into the trie
    while (i < n && nums[i] <= it.first)
    {
      tr.insert(nums[i]);
      i++;
    }

    if (i != 0)
    {
      ans[it.second.second] = tr.getMax(it.second.first);
    }
    else
    {
      ans[it.second.second] = -1;
    }
  }
  return ans;
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

  int m;
  cin >> m;
  vector<vector<int>> queries;
  for (int i = 0; i < m; i++)
  {
    int q1, q2;
    cin >> q1 >> q2;
    queries.push_back({q1, q2});
  }
  vector<int> ans = maximizeXor(nums, queries);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  cout << endl;
}