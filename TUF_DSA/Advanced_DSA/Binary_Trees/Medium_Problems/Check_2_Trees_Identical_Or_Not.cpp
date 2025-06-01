#include "BinaryTree.h"

bool isSameTree(BTreeNode *p, BTreeNode *q)
{
  // your code goes here
  if (p == nullptr || q == nullptr)
  {
    return (p == q);
  }
  return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
  BTreeNode *root1 = root1->takeInputLevelWise();
  BTreeNode *root2 = root2->takeInputLevelWise();

  cout << isSameTree(root1, root2) << endl;
  delete root1;
  delete root2;
}