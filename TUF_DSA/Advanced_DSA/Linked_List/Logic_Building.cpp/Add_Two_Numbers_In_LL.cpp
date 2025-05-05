#include "Node.h"

Node *addTwoNumbers(Node *l1, Node *l2)
{
  Node *head = nullptr;
  Node *temp = nullptr;
  int carry = 0;
  while (l1 != nullptr || l2 != nullptr || carry)
  {
    int sum = 0;
    if (l1 != nullptr)
    {
      sum += l1->data;
      l1 = l1->next;
    }
    if (l2 != nullptr)
    {
      sum += l2->data;
      l2 = l2->next;
    }
    sum += carry;
    carry = sum / 10;
    Node *newNode = new Node(sum % 10);
    if (head == nullptr)
    {
      head = newNode;
      temp = newNode;
    }
    else
    {
      temp->next = newNode;
      temp = newNode;
    }
  }
  return head;
}

int main()
{
  Node *head1 = head1->takeInput();
  Node *head2 = head2->takeInput();
  Node *head3 = addTwoNumbers(head1, head2);
  head3->print(head3);
  delete head1;
  delete head2;
  delete head3;
}