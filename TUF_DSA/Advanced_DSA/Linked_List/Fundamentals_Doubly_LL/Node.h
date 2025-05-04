#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
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
        tail = newNode;
      }
      else if (head->next == nullptr)
      {
        head->next = newNode;
        newNode->prev = head;
        tail = newNode;
      }
      else
      {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
      cin >> data;
    }
    return head;
  }

  void print(Node *head)
  {
    Node *current = head;
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};