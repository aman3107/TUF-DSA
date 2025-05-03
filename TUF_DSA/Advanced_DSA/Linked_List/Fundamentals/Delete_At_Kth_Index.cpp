#include "Node.h"

Node *deleteKthIIndex(Node *head, int k)
{
  if (head == nullptr)
  {
    return head;
  }
  if (k == 1)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  int c = 1;
  Node *prev = nullptr;
  Node *temp = head;

  while (temp != nullptr && c != k)
  {
    prev = temp;
    temp = temp->next;
    c++;
  }
  if (k > c)
  {
    return head;
  }
  else
  {
    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return head;
  }
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