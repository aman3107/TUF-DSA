#include "Node.h"

int findLengthOfLoopBrute(Node *head)
{
  unordered_map<Node *, int> ump;
  Node *temp = head;
  int timer = 1;
  while (temp != nullptr)
  {
    if (ump.find(temp) != ump.end())
    {
      int ans = timer - ump[temp];
      return ans;
    }
    ump[temp] = timer;
    timer++;
    temp = temp->next;
  }
  return 0;
}

int findLengthOfLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {

      fast = fast->next;
      int c = 1;
      while (fast != slow)
      {
        c++;
        fast = fast->next;
      }
      return c;
    }
  }
  return 0;
}

int main()
{
  Node *head = head->takeInput();
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = head->next;
  cout << findLengthOfLoopBrute(head) << endl;
  delete temp;
  delete head;
}