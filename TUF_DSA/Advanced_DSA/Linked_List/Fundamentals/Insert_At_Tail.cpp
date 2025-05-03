#include "Node.h"

Node *insertAtTail(Node *head, int data)
{
  Node *newNode = new Node(data);
  if (head == nullptr)
  {
    head = newNode;
    return head;
  }
  else
  {
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
  }
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  head = insertAtTail(head, data);
  head->print(head);
  delete head;
}