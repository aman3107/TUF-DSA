#include <bits/stdc++.h>
using namespace std;

/*
✅ Problem Statement:
Given an array of strings strs, group the anagrams together.
An anagram is a word formed by rearranging the letters of another word.

Example Input:
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
Expected Output:

[
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]
🧠 Intuition:
Two words are anagrams if they contain the exact same number of each character.
So instead of sorting each string (which is O(k log k)), we can:
Count the frequency of each character.
Use that frequency vector as a key to group words.

🔍 Approach:
Initialize a map:
unordered_map<string, vector<string>> mp to group words by frequency signature.
Iterate through each word:
Create a hash vector of size 26 (for lowercase a-z), initialized to 0.
Count frequency of each character.
Create a unique string key from the frequency vector:
Add a delimiter (e.g., "#") to ensure no ambiguity in keys like 1#11 vs 11#1.
Use the key to group anagrams in the map.
Collect all grouped anagrams from the map and return as a 2D vector.

✅ Example Walkthrough:
For strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
"eat" → hash = [1,0,0,...,1,...,1,...] → key = "#1#0#0#0#1#0..."
"tea" → same key as "eat" → grouped together
"tan" / "nat" → same hash → grouped
"bat" → different hash → new group
⏱️ Time and Space Complexity:
Time:

O(n * k)

n: number of words

k: average word length

Why? O(k) for hashing each word (vs O(k log k) if sorting was used)

Space:

O(n * k) for storing groups and hash keys.

*/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  unordered_map<string, vector<string>> mp;
  for (auto &word : strs)
  {
    vector<int> hash(26, 0);
    for (auto c : word)
    {
      hash[c - 'a']++;
    }
    string key;
    for (int i = 0; i < 26; i++)
    {
      key += "#";
      key += to_string(hash[i]);
    }
    mp[key].push_back(word);
  }
  vector<vector<string>> ans;
  for (auto &it : mp)
  {
    ans.push_back(it.second);
  }
  return ans;
}

/*

Intuition:
All anagrams, when sorted alphabetically, will become identical strings.

Example:
"eat" → "aet"
"tea" → "aet"
"ate" → "aet"
→ All belong to the same group.

So, we can use the sorted version of each word as a key in a map to group anagrams together.

🧱 Approach:
Step-by-step:
Create a hash map:
unordered_map<string, vector<string>> mp
Key: sorted string
Value: list of original words that map to that sorted form.
For each word in the input list:
Make a copy of the word: string sorted = word
Sort it: sort(sorted.begin(), sorted.end())
Use the sorted string as the key: mp[sorted].push_back(word)
Collect grouped anagrams:
Iterate over the map and collect all mp[key] into a final result vector.
*/

vector<vector<string>> groupAnagramsUsingSorting(vector<string> &strs)
{
  // Create a hashmap to store the keys for the anagrams
  unordered_map<string, vector<string>> mp;
  // for each word
  for (auto &word : strs)
  {
    // take the word in sorted variable
    string sorted = word;
    // sort the word
    sort(sorted.begin(), sorted.end());
    // store the word in a sorted key
    mp[sorted].push_back(word);
  }
  vector<vector<string>> ans;
  for (auto &it : mp)
  {
    // push all the anagrams into the ans array
    ans.push_back(it.second);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> str;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    str.push_back(s);
  }
  vector<vector<string>> ans = groupAnagrams(str);
  for (auto &it : ans)
  {
    for (auto &it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
}