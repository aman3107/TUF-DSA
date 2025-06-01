#include "BinaryTree.h"

bool symmetry(BTreeNode *left, BTreeNode *right)
{
  if (left == nullptr && right == nullptr)
  {
    return true;
  }
  if (left == nullptr || right == nullptr)
  {
    return false;
  }
  if (left->data != right->data)
  {
    return false;
  }
  return symmetry(left->left, right->right) && symmetry(left->right, right->left);
}

bool isSymmetric(BTreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return true;
  }
  return symmetry(root->left, root->right);
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  cout << isSymmetric(root) << endl;
  delete root;
}