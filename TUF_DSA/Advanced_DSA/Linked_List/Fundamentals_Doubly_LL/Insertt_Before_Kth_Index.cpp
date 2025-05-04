#include "Node.h"
using namespace std;

Node *insertBeforekthIndex(Node *head, int data, int k)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    return head;
  }
  if (k == 1)
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
  }
  int c = 1;
  Node *temp = head;
  while (temp->next != nullptr && c != k)
  {
    temp = temp->next;
    c++;
  }
  if (c == k)
  {
    Node *prev = temp->prev;
    newNode->prev = prev;
    newNode->next = temp;
    temp->prev = newNode;
    prev->next = newNode;
  }

  return head;
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  int k;
  cin >> k;
  head = insertBeforekthIndex(head, data, k);
  head->print(head);
  delete head;
}