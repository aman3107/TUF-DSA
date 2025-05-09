#include "Node.h"

Node *getIntersectionNode(Node *head1, Node *head2)
{
  if (head1 == nullptr || head2 == nullptr)
  {
    return nullptr;
  }
  Node *temp1 = head1;
  Node *temp2 = head2;
  while (temp1 != temp2)
  {
    temp1 = temp1->next;
    temp2 = temp2->next;

    if (temp1 == temp2)
    {
      return temp1;
    }
    if (temp1 == nullptr)
    {
      temp1 = head2;
    }
    if (temp2 == nullptr)
    {
      temp2 = head1;
    }
  }
  return temp1;
}

int llLength(Node *head)
{
  Node *temp = head;
  int c = 0;
  while (temp != nullptr)
  {
    c++;
    temp = temp->next;
  }
  return c;
}

Node *getIntersectionNodeBetterHelper(Node *head1, Node *head2, int d)
{
  while (d > 0)
  {
    head2 = head2->next;
    d--;
  }
  while (head1 != nullptr)
  {
    if (head1 == head2)
    {
      return head1;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  return nullptr;
}

Node *getIntersectionNodeBetter(Node *head1, Node *head2)
{
  int n1 = llLength(head1);
  int n2 = llLength(head2);

  if (n1 < n2)
  {
    return getIntersectionNodeBetterHelper(head1, head2, n2 - n1);
  }
  else
  {
    return getIntersectionNodeBetterHelper(head2, head1, n1 - n2);
  }
}
Node *getIntersectionNodeBrute(Node *headA, Node *headB)
{
  unordered_map<Node *, int> ump;
  while (headA != NULL)
  {
    ump[headA] = 1;
    headA = headA->next;
  }
  // for (unordered_map<Node *, int>::iterator it = ump.begin(); it != ump.end(); it++)
  // {
  //   Node *temp = it->first;
  //   cout << temp->next << endl;
  // }
  while (headB != nullptr)
  {
    if (ump[headB] == 1)
    {
      return headB;
    }
    headB = headB->next;
  }
  return nullptr;
}

int main()
{
  Node *head1 = head1->takeInput();
  Node *head2 = head2->takeInput();

  Node *ans = getIntersectionNodeBrute(head1, head2);
  if (ans == nullptr)
  {
    cout << "Not found " << endl;
  }
  else
  {
    cout << ans->data << endl;
  }
  delete head1;
  delete head2;
  delete ans;
}