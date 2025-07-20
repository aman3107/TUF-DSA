#include <bits/stdc++.h>
using namespace std;

class Node
{
  Node *links[26] = {nullptr};

public:
  bool containsKey(char ch)
  {
    return links[ch - 'a'] != nullptr;
  }
  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }
  Node *get(char ch)
  {
    return links[ch - 'a'];
  }
};

int countDistinctSubstring(string s)
{
  // your code goes here
  Node *root = new Node();
  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {
    Node *node = root;
    for (int j = i; j < s.size(); j++)
    {
      if (!node->containsKey(s[j]))
      {
        node->put(s[j], new Node());
        count++;
      }
      node = node->get(s[j]);
    }
  }
  return count + 1;
}

int main()
{
  string s;
  cin >> s;
  cout << countDistinctSubstring(s) << endl;
}