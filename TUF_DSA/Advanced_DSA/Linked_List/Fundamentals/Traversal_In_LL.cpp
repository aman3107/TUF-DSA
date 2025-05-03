#include "Node.h"

vector<int> LLTraversal(Node *head)
{
  vector<int> ans;
  Node *current = head;
  while (current != nullptr)
  {
    ans.push_back(current->data);
    current = current->next;
  }
  return ans;
}

int main()
{
  Node *head = head->takeInput();
  head->print(head);
  vector<int> ans = LLTraversal(head);
  for (int a : ans)
  {
    cout << a << " ";
  }
  cout << endl;

  delete head;
}