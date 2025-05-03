#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }

  void print(Node *head)
  {
    if (head == nullptr)
    {
      return;
    }
    Node *current = head;
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
  }

  Node *takeInput()
  {
    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;

    while (data != -1)
    {
      Node *newNode = new Node(data);
      if (head == nullptr)
      {
        head = newNode;
        tail = head;
      }
      else
      {
        tail->next = newNode;
        tail = newNode;
      }
      cin >> data;
    }
    return head;
  }
};