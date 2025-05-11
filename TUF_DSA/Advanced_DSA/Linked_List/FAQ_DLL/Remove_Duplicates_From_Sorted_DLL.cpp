#include "Node.h"

Node *removeDuplicates(Node *head)
{
  if (head == nullptr && head->next == nullptr)
  {
    return head;
  }
  Node *temp = head;
  while (temp != nullptr && temp->next != nullptr)
  {
    Node *nextNode = temp->next;
    while (nextNode != nullptr && nextNode->data == temp->data)
    {
      Node *delNode = nextNode;
      nextNode = nextNode->next;
      delete delNode;
    }
    temp->next = nextNode;
    if (nextNode)
    {
      nextNode->prev = temp;
    }
    temp = temp->next;
  }
  return head;
}

int main()
{
  Node *head = head->takeInput();
  head = removeDuplicates(head);
  head->print(head);
  delete head;
}