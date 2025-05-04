#include "Node.h"
using namespace std;

void insertBeforeNode(Node *head, int data, int val)
{
  Node *newNode = new Node(val);
  Node *temp = head;
  while (temp != nullptr)
  {
    if (temp->data == data)
    {
      Node *prev = temp->prev;
      newNode->prev = prev;
      newNode->next = temp;
      temp->prev = newNode;
      prev->next = newNode;
      break;
    }
    temp = temp->next;
  }
}

int main()
{
  Node *head = head->takeInput();
  int data;
  cin >> data;
  int k;
  cin >> k;
  insertBeforeNode(head, data, k);
  head->print(head);
  delete head;
}