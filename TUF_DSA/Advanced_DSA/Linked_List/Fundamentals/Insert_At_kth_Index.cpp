#include "Node.h"

Node *insertAtkthIndex(Node *head, int k, int data)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    head = newNode;
    return head;
  }
  if (k == 1)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }
  Node *prev = nullptr;
  Node *temp = head;
  int c = 1;
  while (temp != nullptr && c != k)
  {
    prev = temp;
    temp = temp->next;
    c++;
  }
  if (c == k)
  {
    newNode->next = temp;
    prev->next = newNode;
    return head;
  }
  else
  {
    return head;
  }
}

int main()
{
  Node *head = head->takeInput();
  int k;
  cin >> k;
  int data;
  cin >> data;
  head = insertAtkthIndex(head, k, data);
  head->print(head);
  delete head;
}