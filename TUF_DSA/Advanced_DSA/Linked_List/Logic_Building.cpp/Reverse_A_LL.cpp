#include "Node.h"

Node *reverseListRecursive(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *newNode = reverseListRecursive(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newNode;
}

Node *reverseList(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  Node *temp = head;
  Node *prev = nullptr;
  while (temp != nullptr)
  {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

int main()
{
  Node *head = head->takeInput();
  head = reverseListRecursive(head);
  head->print(head);
  delete head;
}