#include "BinaryTree.h"
int findLeftHeight(TreeNode *root)
{
  int height = 0;
  while (root)
  {
    height++;
    root = root->left;
  }
  return height;
}

int findRightHeight(TreeNode *root)
{
  int height = 0;
  while (root)
  {
    height++;
    root = root->right;
  }
  return height;
}

int countNodes(TreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  int lH = findLeftHeight(root);
  int rH = findRightHeight(root);
  if (lH == rH)
  {
    return (1 << lH) - 1;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << countNodes(root) << endl;
  delete root;
}