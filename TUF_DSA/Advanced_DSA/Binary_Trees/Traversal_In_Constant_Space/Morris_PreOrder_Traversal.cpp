#include "BinaryTree.h"

vector<int> getpreorder(TreeNode *root)
{
  // your code goes here
  vector<int> preorder;
  TreeNode *curr = root;
  while (curr != nullptr)
  {
    if (curr->left == nullptr)
    {
      preorder.push_back(curr->data);
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
        preorder.push_back(curr->data);
        prev->right = curr;
        curr = curr->left;
      }
      else
      {
        prev->right = nullptr;

        curr = curr->right;
      }
    }
  }
  return preorder;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = getpreorder(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}