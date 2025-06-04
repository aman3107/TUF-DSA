#include "BinaryTree.h"

void rightSideViewHelper(TreeNode *root, int level, vector<int> &ans)
{
  if (root == nullptr)
  {
    return;
  }
  if (level == ans.size())
  {
    ans.push_back(root->data);
  }
  rightSideViewHelper(root->right, level + 1, ans);
  rightSideViewHelper(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
  // your code goes here
  vector<int> ans;
  rightSideViewHelper(root, 0, ans);
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = rightSideView(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}