#include "Node.h"

Node *deleteAtValueX(Node *head, int k)
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
  while (temp != nullptr)
  {
    if (temp->data == k)
    {
      if (temp->next == nullptr)
      {
        Node *prev = temp->prev;
        Node *front = temp->next;
        prev->next = front;
        prev = nullptr;
        delete temp;
      }
      else
      {
        Node *prev = temp->prev;
        Node *front = temp->next;
        prev->next = front;
        front->prev = prev;
        prev = nullptr;
        front = nullptr;
        delete temp;
      }
      break;
    }
    temp = temp->next;
  }

  return head;
}

int main()
{
  Node *head = head->takeInput();
  int k;
  cin >> k;
  head = deleteAtValueX(head, k);
  head->print(head);
  delete head;
}