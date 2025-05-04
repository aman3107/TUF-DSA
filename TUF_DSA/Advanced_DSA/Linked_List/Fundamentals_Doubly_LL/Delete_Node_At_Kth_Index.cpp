#include "Node.h"

Node *deleteAtKthIndex(Node *head, int k)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    return nullptr;
  }

  if (k == 1)
  {
    if (head->next == nullptr)
    {
      delete head;
      return nullptr;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      head->prev = nullptr;
      temp->next = nullptr;
      delete temp;
      return head;
    }
  }

  Node *temp = head;
  int c = 1;
  while (temp->next != nullptr && c != k)
  {
    temp = temp->next;
    c++;
  }
  Node *prev = temp->prev;
  Node *front = temp->next;
  if (c == k)
  {
    if (temp->next != nullptr)
    {
      prev->next = front;
      front->prev = prev;
      prev = nullptr;
      front = nullptr;
      delete temp;
    }
    else
    {
      prev->next = nullptr;
      prev = nullptr;
      delete temp;
    }
  }
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int k;
  cin >> k;
  head = deleteAtKthIndex(head, k);
  head->print(head);
  delete head;
}