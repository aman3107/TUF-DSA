#include "Node.h"
using namespace std;

Node *insertBeforeTail(Node *head, int data)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    head = newNode;
    return newNode;
  }
  if (head->next == nullptr)
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
  }
  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  Node *front = temp->next;
  newNode->prev = temp;
  newNode->next = front;
  front->prev = newNode;
  temp->next = newNode;
  return head;
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  head = insertBeforeTail(head, data);
  head->print(head);
  delete head;
}