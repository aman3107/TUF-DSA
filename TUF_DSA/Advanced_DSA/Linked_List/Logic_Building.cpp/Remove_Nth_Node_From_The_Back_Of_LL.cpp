#include "Node.h"

Node *removeNthFromEndOptimal(Node *head, int n)
{
  if (head == nullptr)
  {
    return head;
  }
  Node *fast = head;
  for (int i = 0; i < n; i++)
  {
    fast = fast->next;
  }
  if (fast == nullptr)
  {
    Node *newNode = head->next;
    delete head;
    return newNode;
  }
  Node *slow = head;
  while (fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next;
  }

  Node *delNode = slow->next;
  slow->next = delNode->next;
  delete delNode;
  return head;
}

Node *removeNthFromEndBrute(Node *head, int n)
{
  Node *temp = head;
  int c = 0;
  while (temp != nullptr)
  {
    c++;
    temp = temp->next;
  }
  if (c == n)
  {
    Node *newNode = head->next;
    delete (head);
    return newNode;
  }
  int rem = c - n;
  temp = head;
  while (temp != nullptr)
  {
    rem--;
    if (rem == 0)
    {
      break;
    }
    temp = temp->next;
  }
  Node *newNode = temp->next;
  temp->next = newNode->next;
  delete newNode;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int n;
  cin >> n;
  // head = removeNthFromEndBrute(head, n);
  head = removeNthFromEndOptimal(head, n);
  head->print(head);
  delete head;
}