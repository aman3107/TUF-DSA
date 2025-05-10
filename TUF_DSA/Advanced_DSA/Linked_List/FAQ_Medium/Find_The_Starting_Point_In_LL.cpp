#include "Node.h"

Node *findStartingPoint(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr)
  {
    // 1. Detecting the loop
    slow = slow->next;
    fast = fast->next->next;
    // Loop detected
    if (slow == fast)
    {
      // Put slow again at the head;
      slow = head;
      // 2. Check if both are  pointing to same node i.e the starting point of the loop
      while (slow != fast)
      {
        // Move both by one node
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

Node *findStartingPointBrute(Node *head)
{
  unordered_map<Node *, int> ump;
  Node *temp = head;
  while (temp != nullptr)
  {
    if (ump.find(temp) != ump.end())
    {
      return temp;
    }
    ump[temp]++;
    temp = temp->next;
  }
  return nullptr;
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
  Node *ans = findStartingPoint(head);
  if (ans == nullptr)
  {
    cout << "Not found loop :" << endl;
  }
  else
  {
    cout << ans->data << endl;
  }
  delete temp;
  delete head;
}