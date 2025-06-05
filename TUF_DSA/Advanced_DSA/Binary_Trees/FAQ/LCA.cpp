#include "BinaryTree.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  // your code goes here
  if (root == nullptr)
  {
    return nullptr;
  }
  if (root->data == p->data)
  {
    return p;
  }
  if (root->data == q->data)
  {
    return q;
  }
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left == nullptr && right == nullptr)
  {
    return nullptr;
  }
  else if (right == nullptr)
  {
    return left;
  }
  else if (left == nullptr)
  {
    return right;
  }
  else
  {
    return root;
  }
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  int a, b;
  cin >> a >> b;
  TreeNode *p = new TreeNode(a);
  TreeNode *q = new TreeNode(b);
  TreeNode *ans = lowestCommonAncestor(root, p, q);
  cout << ans->data << endl;
  delete root;
}