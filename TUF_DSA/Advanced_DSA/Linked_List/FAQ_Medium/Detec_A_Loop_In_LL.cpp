#include "Node.h"

bool hasCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      return true;
    }
  }
  return false;
}

bool hasCycleBrute(Node *head)
{
  unordered_map<Node *, int> ump;
  Node *temp = head;
  while (temp != nullptr)
  {
    ump[temp]++;
    if (ump[temp] > 1)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int main()
{
  Node *head = head->takeInput();
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = head->next->next;
  cout << hasCycle(head) << endl;
  delete temp;
  delete head;
}