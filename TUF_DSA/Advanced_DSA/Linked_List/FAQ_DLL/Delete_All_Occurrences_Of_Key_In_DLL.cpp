#include "Node.h"

Node *deleteAllOccurrences(Node *head, int target)
{
  if (head == nullptr)
  {
    return nullptr;
  }
  Node *temp = head;
  while (temp != nullptr)
  {
    if (temp->data == target)
    {
      if (temp == head)
      {
        head = temp->next;
      }
      Node *nextNode = temp->next;
      Node *prevNode = temp->prev;
      if (nextNode)
      {
        nextNode->prev = prevNode;
      }
      if (prevNode)
      {
        prevNode->next = nextNode;
      }
      delete temp;
      temp = nextNode;
    }
    else
    {
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int target;
  cin >> target;
  head = deleteAllOccurrences(head, target);
  head->print(head);
  delete head;
}