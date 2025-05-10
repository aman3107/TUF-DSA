#include "Node.h"

Node *middleOfLinkedList(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node *middleOfLinkedListBrute(Node *head)
{

  int c = 0;
  Node *temp = head;
  while (temp != nullptr)
  {
    c++;
    temp = temp->next;
  }
  int mid = (c / 2) + 1;
  temp = head;
  while (temp != nullptr)
  {
    mid--;
    if (mid == 0)
    {
      break;
    }
    temp = temp->next;
  }
  return temp;
}

int main()
{
  Node *head = head->takeInput();
  Node *ans = middleOfLinkedList(head);
  cout << ans->data << endl;
  delete head;
  delete ans;
}