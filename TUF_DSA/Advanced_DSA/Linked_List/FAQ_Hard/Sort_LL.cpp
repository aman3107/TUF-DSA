#include "Node.h"

Node *mergeTwoLists(Node *l1, Node *l2)
{
  Node *l3 = new Node(-1);
  Node *temp = l3;
  while (l1 != nullptr && l2 != nullptr)
  {
    if (l1->data <= l2->data)
    {
      temp->next = l1;
      l1 = l1->next;
    }
    else
    {
      temp->next = l2;
      l2 = l2->next;
    }
    temp = temp->next;
  }
  if (l1 != nullptr)
  {
    temp->next = l1;
  }
  else
  {
    temp->next = l2;
  }
  return l3->next;
}

Node *middleLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  Node *slow = head;
  Node *fast = head->next;
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node *sortList(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *midNode = middleLL(head);
  Node *right = midNode->next;
  midNode->next = nullptr;
  Node *left = head;

  left = sortList(left);
  right = sortList(right);

  return mergeTwoLists(left, right);
}

int main()
{
  Node *head = head->takeInput();
  head = sortList(head);
  head->print(head);
  delete head;
}