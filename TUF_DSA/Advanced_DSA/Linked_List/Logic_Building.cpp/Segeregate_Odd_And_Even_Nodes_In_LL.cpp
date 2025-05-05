#include "Node.h"

Node *oddEvenList2(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  vector<int> arr;
  Node *temp = head;
  while (temp != nullptr && temp->next != nullptr)
  {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp != nullptr)
  {
    arr.push_back(temp->data);
  }
  temp = head->next;
  while (temp != nullptr && temp->next != nullptr)
  {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp != nullptr)
  {
    arr.push_back(temp->data);
  }

  int i = 0;
  temp = head;
  while (temp != nullptr)
  {
    temp->data = arr[i];
    temp = temp->next;
    i++;
  }
  return head;
}

Node *oddEvenList(Node *head)
{
  if (head == nullptr)
  {
    return head;
  }

  Node *oddHead = nullptr;
  Node *oddTemp = nullptr;
  Node *evenHead = nullptr;
  Node *evenTemp = nullptr;

  int c = 1;
  while (head != nullptr)
  {
    Node *newNode = new Node(head->data);
    if (c % 2)
    {
      if (oddHead == nullptr)
      {
        oddHead = newNode;
        oddTemp = newNode;
      }
      else
      {
        oddTemp->next = newNode;
        oddTemp = newNode;
      }
    }
    else
    {
      if (evenHead == nullptr)
      {
        evenHead = newNode;
        evenTemp = newNode;
      }
      else
      {
        evenTemp->next = newNode;
        evenTemp = newNode;
      }
    }
    c++;
    head = head->next;
  }
  oddTemp->next = evenHead;
  return oddHead;
}

int main()
{
  Node *head = head->takeInput();
  head = oddEvenList2(head);
  head->print(head);
  delete head;
}