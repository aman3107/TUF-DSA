#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

public:
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

Node *arrToLL(int arr[], int n)
{
  Node *head = new Node(arr[0]);
  Node *tail = head;
  for (int i = 1; i < n; i++)
  {
    Node *newNode = new Node(arr[i]);
    tail->next = newNode;
    tail = newNode;
  }
  return head;
}

void print(Node *head)
{
  Node *current = head;
  while (current != nullptr)
  {
    cout << current->data << " ";
    current = current->next;
  }
}

int main()
{
  int arr[] = {2, 1, 3, 8};
  Node *n1 = new Node(1);
  cout << n1->data << endl;

  Node *head = arrToLL(arr, 4);
  print(head);
  delete n1;
  delete head;
}