#include "BinaryTree.h"

TreeNode *searchBST(TreeNode *root, int val)
{
  // your code goes here
  if (root == nullptr)
  {
    return nullptr;
  }

  if (root->data == val)
  {
    return root;
  }
  if (root != nullptr)
  {
    if (root->data > val)
      root = searchBST(root->left, val);
    else
      root = searchBST(root->right, val);
  }
  return root;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter value " << endl;
  int val;
  cin >> val;
  TreeNode *ans = searchBST(root, val);
  ans->print(ans);
  delete ans;
  delete root;
}