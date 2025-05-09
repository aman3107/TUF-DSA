#include "Node.h"

bool isPalindromeBrute(Node *head)
{
  stack<int> st;
  Node *temp = head;
  while (temp != nullptr)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr)
  {
    if (st.top() != temp->data)
    {
      return false;
    }
    temp = temp->next;
    st.pop();
  }
  return true;
}

Node *reverseLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

bool isPalindrome(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return true;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *newHead = reverseLL(slow->next);
  Node *first = head;
  Node *second = newHead;
  while (second != nullptr)
  {
    if (first->data != second->data)
    {
      reverseLL(newHead);
      return false;
    }
    second = second->next;
    first = first->next;
  }
  reverseLL(newHead);
  return true;
}

int main()
{
  Node *head = head->takeInput();
  // head = reverseLL(head);
  // head->print(head);
  cout << isPalindromeBrute(head);
  delete head;
}