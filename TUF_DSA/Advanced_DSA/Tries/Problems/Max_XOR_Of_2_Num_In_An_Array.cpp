#include <bits/stdc++.h>
using namespace std;

/*
💡 Intuition:
The XOR of two numbers is maximum when their bits differ as much as possible.
For example:

5 → 0101
10 → 1010
5 ^ 10 = 1111 = 15 → maximally different bits
So, to maximize XOR, we want to:
For each number, find another number that has the opposite bits at the highest positions.
To do this efficiently:
Use a Trie to store binary representations of all numbers.
For each number, try to take opposite bits in the Trie to construct the max XOR.

🧠 Approach:
Step 1: Use a Trie to store the bits
Each number is represented as a 32-bit binary.
Insert each bit (from MSB to LSB) into the Trie.
At each level of the Trie, a node has 2 possible paths: 0 and 1.

Step 2: For each number, find the number in the Trie that gives maximum XOR:
At each bit position, try to go in the opposite direction of the current bit to get a 1 in XOR.
If opposite bit exists in Trie, take that path and set that bit in result.
If not, go in the same direction (bit value = 0 in XOR).

Step 3: Track and return the maximum XOR found.
🛠 Breakdown of Code Logic:
🔹 insert(int num):
Stores the 32-bit representation of num into the Trie.
Builds the Trie level by level (bit by bit).

🔹 getMax(int num):
Traverses the Trie to find the number that gives the highest XOR with num.
Uses the idea that 1 ^ 0 = 1 (desirable), so we try to go in the opposite direction of each bit.

🔹 findMaximumXOR(vector<int>& nums):
Inserts all numbers into the Trie.
For each number in the array, finds the best match from Trie to maximize XOR.
Tracks and returns the highest XOR value found.

📈 Time & Space Complexity:
Operation	Complexity
Insert One Number into Trie	O(32) = O(1)
Get Max XOR for One Number	O(32) = O(1)
Total Time	O(n)
Space (Trie Nodes)	O(32 × n) = O(n)
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

int findMaximumXOR(vector<int> &nums)
{
  // your code goes here
  Trie tr;
  for (int i = 0; i < nums.size(); i++)
  {
    tr.insert(nums[i]);
  }
  int maxi = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    maxi = max(maxi, tr.getMax(nums[i]));
  }
  return maxi;
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
  cout << findMaximumXOR(nums) << endl;
}