#include "Node.h"

Node *deleteKthIIndex(Node *head, int X)
{
  if (head == nullptr)
  {
    return head;
  }
  if (head->data == X)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node *prev = nullptr;
  Node *temp = head;

  while (temp != nullptr)
  {
    if (temp->data == X)
    {
      prev->next = temp->next;
      temp->next = nullptr;
      delete temp;
      return head;
    }
    prev = temp;
    temp = temp->next;
  }

  return head;
}

int main()
{
  Node *head = head->takeInput();
  int k;
  cin >> k;
  head = deleteKthIIndex(head, k);
  head->print(head);
  delete head;
}