#include "BinaryTree.h"

int maxDepthIterative(BTreeNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  queue<BTreeNode *> q;
  q.push(root);
  int level = 0;
  BTreeNode *node;
  while (!q.empty())
  {
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
      node = q.front();
      q.pop();
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    level++;
  }
  return level;
}

int maxDepth(BTreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  cout << maxDepthIterative(root) << endl;
  delete root;
}