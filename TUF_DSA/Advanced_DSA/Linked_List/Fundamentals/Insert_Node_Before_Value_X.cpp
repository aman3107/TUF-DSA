#include "Node.h"

Node *insertAtBeforeX(Node *head, int data, int x)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    return head;
  }
  if (head->data == x)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }
  Node *prev = nullptr;
  Node *temp = head;
  while (temp != nullptr)
  {
    if (temp->data == x)
    {
      newNode->next = temp;
      prev->next = newNode;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int x;
  cin >> x;
  int data;
  cin >> data;
  head = insertAtBeforeX(head, data, x);
  head->print(head);
  delete head;
}