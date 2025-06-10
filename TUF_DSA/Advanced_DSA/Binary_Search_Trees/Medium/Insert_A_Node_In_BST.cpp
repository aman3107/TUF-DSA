#include "BinaryTree.h"

TreeNode *insertIntoBST1(TreeNode *root, int val)
{
  // your code goes here
  if (root == nullptr)
  {
    return new TreeNode(val);
  }
  TreeNode *curr = root;
  while (true)
  {
    if (curr->data <= val)
    {
      if (curr->right != nullptr)
        curr = curr->right;
      else
      {
        curr->right = new TreeNode(val);
        break;
      }
    }
    else
    {
      if (curr->left != nullptr)
      {
        curr = curr->left;
      }
      else
      {
        curr->left = new TreeNode(val);
        break;
      }
    }
  }
  return root;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
  // your code goes here
  if (root == nullptr)
  {
    TreeNode *newNode = new TreeNode(val);
    return newNode;
  }
  if (root->data > val)
  {
    root->left = insertIntoBST(root->left, val);
  }
  if (root->data < val)
  {
    root->right = insertIntoBST(root->right, val);
  }
  return root;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter val :" << endl;
  int val;
  cin >> val;
  root = insertIntoBST1(root, val);
  root->print(root);
  delete root;
}