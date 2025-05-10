#include "Node.h"

Node *deleteMiddle(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  fast = fast->next->next;
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *delNode = slow->next;
  slow->next = delNode->next;
  delete delNode;
  return head;
}

Node *deleteMiddleBrute(Node *head)
{
  int c = 0;
  Node *temp = head;
  while (temp != nullptr)
  {
    c++;
    temp = temp->next;
  }
  int mid = (c / 2);
  temp = head;

  while (temp != nullptr)
  {
    mid--;
    if (mid == 0)
    {
      break;
    }
    temp = temp->next;
  }

  Node *delNode = temp->next;
  temp->next = delNode->next;
  delete delNode;
  return head;
}

int main()
{
  Node *head = head->takeInput();

  head = deleteMiddleBrute(head);
  head->print(head);
  delete head;
}