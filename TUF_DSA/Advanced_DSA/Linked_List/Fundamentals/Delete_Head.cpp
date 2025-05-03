#include "Node.h"

Node *deleteHead(Node *head)
{
  if (head == nullptr)
  {
    return head;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  head = deleteHead(head);
  head->print(head);
  delete head;
}