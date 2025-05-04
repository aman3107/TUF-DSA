#include "Node.h"

Node *arrayToLinkedList(vector<int> &nums)
{
  Node *head = nullptr;
  Node *tail = nullptr;
  for (int i = 0; i < nums.size(); i++)
  {
    Node *newNode = new Node(nums[i]);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else if (head->next == nullptr)
    {
      head->next = newNode;
      newNode->prev = head;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  Node *head = arrayToLinkedList(arr);
  head->print(head);
  delete head;
}