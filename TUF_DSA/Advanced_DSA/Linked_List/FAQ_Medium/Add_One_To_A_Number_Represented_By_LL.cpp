#include "Node.h"

Node *reverseList(Node *head)
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

int hasCarry(Node *head)
{
  if (head == nullptr)
  {
    return 1;
  }
  int carry = hasCarry(head->next);
  head->data += carry;
  if (head->data < 10)
  {
    return 0;
  }
  head->data = 0;
  return 1;
}

Node *addOneRecursive(Node *head)
{
  int carry = hasCarry(head);
  if (carry == 0)
  {
    return head;
  }
  else
  {
    Node *newNode = new Node(carry);
    newNode->next = head;
    head = newNode;
    return head;
  }
}

Node *addOne(Node *head)
{
  head = reverseList(head);
  Node *temp = head;
  int carry = 1;
  while (temp != nullptr)
  {
    int sum = temp->data;
    sum += carry;
    carry = sum / 10;
    temp->data = sum % 10;
    if (carry == 0)
    {
      break;
    }
    if (temp->next == nullptr && carry != 0)
    {
      temp->next = new Node(carry);
      break;
    }
    temp = temp->next;
  }
  return reverseList(head);
}

int main()
{
  Node *head = head->takeInput();
  head = addOne(head);
  head->print(head);
  delete head;
}