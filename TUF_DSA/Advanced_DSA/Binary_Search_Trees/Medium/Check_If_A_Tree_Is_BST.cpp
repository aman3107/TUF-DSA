#include "BinaryTree.h"

bool isBSTHelper(TreeNode *root, int minVal, int maxVal)
{
  if (root == nullptr)
  {
    return true;
  }
  if (root->data >= maxVal || root->data <= minVal)
  {
    return false;
  }
  return isBSTHelper(root->left, minVal, root->data) && isBSTHelper(root->right, root->data, maxVal);
}

bool isBST(TreeNode *root)
{
  // your code goes here
  return isBSTHelper(root, INT_MIN, INT_MAX);
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << isBST(root) << endl;
  delete root;
}