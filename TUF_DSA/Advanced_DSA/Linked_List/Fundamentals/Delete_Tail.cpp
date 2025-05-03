#include "Node.h"

Node *deleteTail(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    return nullptr;
  }
  Node *previous = nullptr;
  Node *temp = head;
  while (temp->next != nullptr)
  {
    previous = temp;
    temp = temp->next;
  }
  previous->next = nullptr;
  delete temp;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  head = deleteTail(head);
  head->print(head);
  delete head;
}