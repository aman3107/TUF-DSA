#include "Node.h"
using namespace std;

Node *insertHead(Node *head, int data)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    head = newNode;
    return newNode;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  head = insertHead(head, data);
  head->print(head);
  delete head;
}