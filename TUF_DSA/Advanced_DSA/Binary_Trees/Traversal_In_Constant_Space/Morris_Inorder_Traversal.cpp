#include "BinaryTree.h"

vector<int> getInorder(TreeNode *root)
{
  // your code goes here
  vector<int> inorder;
  TreeNode *curr = root;
  while (curr != nullptr)
  {
    if (curr->left == nullptr)
    {
      inorder.push_back(curr->data);
      curr = curr->right;
    }
    else
    {
      TreeNode *prev = curr->left;
      while (prev->right && prev->right != curr)
      {
        prev = prev->right;
      }
      if (prev->right == nullptr)
      {
        prev->right = curr;
        curr = curr->left;
      }
      else
      {
        prev->right = nullptr;
        inorder.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  return inorder;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = getInorder(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}