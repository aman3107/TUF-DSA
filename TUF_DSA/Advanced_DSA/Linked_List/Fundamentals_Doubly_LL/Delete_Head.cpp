#include "Node.h"

Node *deleteHead(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    return nullptr;
  }

  Node *temp = head;
  head = head->next;
  head->prev = nullptr;
  temp->next = nullptr;
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