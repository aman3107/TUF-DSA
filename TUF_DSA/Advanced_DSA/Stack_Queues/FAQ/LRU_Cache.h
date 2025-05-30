#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
  Node *next;
  Node *prev;
  int k;
  int val;

  Node()
  {
    k = -1;
    val = -1;
    next = nullptr;
    prev = nullptr;
  }
  Node(int key, int value)
  {
    k = key;
    val = value;
    next = nullptr;
    prev = nullptr;
  }
};

class LRUCache
{
private:
  unordered_map<int, Node *> mp;
  Node *head;
  Node *tail;
  int cap;

  void deleteNode(Node *node)
  {
    Node *prev = node->prev;
    Node *nextNode = node->next;
    prev->next = nextNode;
    nextNode->prev = prev;
  }

  void insertAfterHead(Node *node)
  {
    Node *nextNode = head->next;
    head->next = node;
    nextNode->prev = node;
    node->next = nextNode;
    node->prev = head;
  }

public:
  LRUCache(int capacity)
  {
    cap = capacity;
    mp.clear();
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }
  int get(int key_)
  {
    if (mp.find(key_) != mp.end())
    {
      Node *node = mp[key_];
      int ans = node->val;
      deleteNode(node);
      insertAfterHead(node);
      return ans;
    }
    else
    {
      return -1;
    }
  }
  void put(int key_, int value)
  {
    if (mp.find(key_) != mp.end())
    {
      Node *node = mp[key_];
      node->val = value;
      deleteNode(node);
      insertAfterHead(node);
      return;
    }
    else
    {
      if (mp.size() == cap)
      {
        Node *node = tail->prev;
        mp.erase(node->k);
        deleteNode(node);
      }
    }
    Node *newNode = new Node(key_, value);
    mp[key_] = newNode;
    insertAfterHead(newNode);
  }
};