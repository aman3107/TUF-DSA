#include <bits/stdc++.h>
using namespace std;

class Node
{
  Node *links[26] = {nullptr};
  int endsWith = 0;
  int countPrefix = 0;

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

  void prefixCountIncrease()
  {
    countPrefix++;
  }
  void endsWithCountIncrease()
  {
    endsWith++;
  }

  int getEndsWith()
  {
    return endsWith;
  }

  int getCountPrefix()
  {
    return countPrefix;
  }

  void prefixCountDecrease()
  {
    countPrefix--;
  }

  void endsWithCountDecrease()
  {
    endsWith--;
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
      node->prefixCountIncrease();
    }
    node->endsWithCountIncrease();
  }

  int countWordsEqualTo(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->getEndsWith();
  }

  int countWordsStartingWith(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->getCountPrefix();
  }

  void erase(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
        return;
      node = node->get(word[i]);
      node->prefixCountDecrease();
    }
    node->endsWithCountDecrease();
  }
};