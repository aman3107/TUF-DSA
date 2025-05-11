#include "Node.h"

Node *leftRotate(Node *head, int k)
{
  if (head == nullptr || head->next == nullptr || k == 0)
  {
    return head;
  }
  int len = 1;
  Node *tail = head;
  while (tail->next != nullptr)
  {
    len++;
    tail = tail->next;
  }

  k = k % len;
  if (k == 0)
  {
    return head;
  }
  tail->next = head;
  while (k > 0)
  {
    k--;
    tail = tail->next;
  }
  head = tail->next;
  tail->next = nullptr;
  return head;
}

Node *rotateRight(Node *head, int k)
{

  if (head == nullptr || head->next == nullptr || k == 0)
  {
    return head;
  }
  int c = 1;
  Node *temp = head;
  while (temp->next != nullptr)
  {
    c++;
    temp = temp->next;
  }
  k = k % c;
  if (k == 0)
  {
    return head;
  }
  int d = c - k;
  temp->next = head;
  while (d > 0)
  {
    d--;
    temp = temp->next;
  }
  head = temp->next;
  temp->next = nullptr;
  return head;
}

Node *rotateRightBrute(Node *head, int k)
{
  for (int i = 0; i < k; i++)
  {
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
      temp = temp->next;
    }
    Node *end = temp->next;
    temp->next = nullptr;
    end->next = head;
    head = end;
  }

  return head;
}

int main()
{
  Node *head = head->takeInput();
  int k;
  cin >> k;
  head = rotateRight(head, k);
  head->print(head);
  delete head;
}