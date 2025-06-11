#include "BinaryTree.h"

TreeNode *lca(TreeNode *root, int p, int q)
{
  // your code goes here
  if (root == nullptr)
  {
    return nullptr;
  }

  if (root->data < p && root->data < q)
  {
    return lca(root->right, p, q);
  }
  if (root->data > p && root->data > q)
  {
    return lca(root->left, p, q);
  }
  return root;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "value of p and q " << endl;
  int p, q;
  cin >> p >> q;
  TreeNode *ans = lca(root, p, q);
  cout << ans->data << endl;
  delete root;
  delete ans;
}