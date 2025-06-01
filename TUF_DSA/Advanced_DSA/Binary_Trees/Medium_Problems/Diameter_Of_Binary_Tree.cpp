#include "BinaryTree.h"

int diameterOfBinaryTreeHelper(BTreeNode *root, int &maxi)
{
  if (root == nullptr)
  {
    return 0;
  }
  int lH = diameterOfBinaryTreeHelper(root->left, maxi);
  int rH = diameterOfBinaryTreeHelper(root->right, maxi);
  maxi = max(maxi, lH + rH);
  return 1 + max(lH, rH);
}

int diameterOfBinaryTreeOptimal(BTreeNode *root)
{
  int maxi = 0;
  diameterOfBinaryTreeHelper(root, maxi);
  return maxi;
}

int maxDepth(BTreeNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  int lH = maxDepth(root->left);
  int rH = maxDepth(root->right);
  return 1 + max(lH, rH);
}

int diameterOfBinaryTree(BTreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  int lH = maxDepth(root->left);
  int rH = maxDepth(root->right);
  int currentDiameter = lH + rH;
  int leftDiameter = diameterOfBinaryTree(root->left);
  int rightDiameter = diameterOfBinaryTree(root->right);

  return max(currentDiameter, max(leftDiameter, rightDiameter));
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  cout << diameterOfBinaryTreeOptimal(root) << endl;
  delete root;
}