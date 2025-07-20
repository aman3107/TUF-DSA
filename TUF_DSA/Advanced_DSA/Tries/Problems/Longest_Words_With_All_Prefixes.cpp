#include <bits/stdc++.h>
using namespace std;

class Node
{
  Node *links[26] = {nullptr};
  bool flag = false;

public:
  bool containsKey(char ch)
  {
    return (links[ch - 'a'] != nullptr);
  }

  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }

  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  void setEnd()
  {
    flag = true;
  }

  bool isEnd()
  {
    return flag;
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

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool isAllPrefixesExists(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
      if (node->isEnd() == false)
      {
        return false;
      }
    }

    return true;
  }
};

string completeString(vector<string> &nums)
{
  // your code goes here
  Trie tr;
  for (int i = 0; i < nums.size(); i++)
  {
    tr.insert(nums[i]);
  }

  string ansStr = "";
  for (int i = 0; i < nums.size(); i++)
  {
    if (tr.isAllPrefixesExists(nums[i]))
    {
      if (nums[i].length() > ansStr.length())
      {
        ansStr = nums[i];
      }
      else if (nums[i].length() == ansStr.length() && nums[i] < ansStr)
      {
        ansStr = nums[i];
      }
    }
  }
  if (ansStr == "")
    return "None";
  return ansStr;
}

int main()
{
  int n;
  cin >> n;
  vector<string> str;
  for (int i = 0; i < n; i++)
  {
    string word;
    cin >> word;
    str.push_back(word);
  }
  cout << completeString(str) << endl;
}