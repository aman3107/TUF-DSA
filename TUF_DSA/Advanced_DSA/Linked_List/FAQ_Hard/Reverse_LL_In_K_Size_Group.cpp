#include "Node.h"

Node *reverseLL(Node *head)
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

Node *getKthNode(Node *head, int k)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    k--;
    if (k == 0)
    {
      break;
    }
    temp = temp->next;
  }
  return temp;
}

Node *reverseKGroup(Node *head, int k)
{
  if (k == 0 || k == 1)
  {
    return head;
  }
  Node *temp = head;
  Node *prev = nullptr;
  while (temp != nullptr)
  {
    Node *kthNode = getKthNode(temp, k);
    if (kthNode == nullptr)
    {
      if (prev)
      {
        prev->next = temp;
      }
      break;
    }
    Node *nextNode = kthNode->next;
    kthNode->next = nullptr;
    reverseLL(temp);
    if (temp == head)
    {
      head = kthNode;
    }
    else
    {
      prev->next = kthNode;
    }
    prev = temp;
    temp = nextNode;
  }
  return head;
}

int main()
{
  Node *head = head->takeInput();
  head = reverseKGroup(head, 3);
  head->print(head);
  delete head;
}