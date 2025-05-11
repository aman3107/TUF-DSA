#include "Node.h"

Node *mergeTwoLists(Node *list1, Node *list2)
{
  Node *head3 = new Node(-1);
  Node *temp = head3;
  while (list1 != nullptr && list2 != nullptr)
  {
    if (list1->data <= list2->data)
    {
      temp->next = list1;
      list1 = list1->next;
    }
    else
    {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  if (list1 != nullptr)
  {
    temp->next = list1;
  }

  else
  {
    temp->next = list2;
  }
  return head3->next;
}

int main()
{
  Node *head1 = head1->takeInput();
  Node *head2 = head2->takeInput();
  Node *ansHead = mergeTwoLists(head1, head2);
  ansHead->print(ansHead);
  delete head1;
  delete head2;
  delete ansHead;
}