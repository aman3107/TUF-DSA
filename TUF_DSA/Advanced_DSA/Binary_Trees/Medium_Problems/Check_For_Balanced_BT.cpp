#include "BinaryTree.h"

int dfs(BTreeNode *root)
{

  if (root == nullptr)
  {
    return true;
  }
  int lH = dfs(root->left);
  int rH = dfs(root->right);

  if (lH == -1 && rH == -1)
  {
    return -1;
  }
  if (abs(lH - rH) > 1)
  {
    return -1;
  }
  return 1 + max(lH, rH);
}

bool isBalanced(BTreeNode *root)
{
  return dfs(root) != -1;
}

int maxDepth(BTreeNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalancedBrute(BTreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return true;
  }
  int lH = maxDepth(root->left);
  int rH = maxDepth(root->right);
  if (abs(lH - rH) <= 1 && isBalanced(root->left) && isBalanced(root->right))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  cout << isBalanced(root) << endl;
  delete root;
}