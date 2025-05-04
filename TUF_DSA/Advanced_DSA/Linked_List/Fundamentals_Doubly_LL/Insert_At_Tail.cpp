#include "Node.h"
using namespace std;

Node *insertTail(Node *head, int data)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    head = newNode;
    return newNode;
  }
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  head = insertTail(head, data);
  head->print(head);
  delete head;
}