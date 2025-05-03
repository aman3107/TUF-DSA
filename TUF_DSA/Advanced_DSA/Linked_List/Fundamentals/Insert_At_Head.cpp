#include "Node.h"

Node *insertAtHead(Node *head, int data)
{
  Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  head = insertAtHead(head, data);
  head->print(head);
  delete head;
}