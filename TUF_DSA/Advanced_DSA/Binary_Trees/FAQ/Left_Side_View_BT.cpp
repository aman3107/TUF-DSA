#include "BinaryTree.h"

void leftSideViewHelper(TreeNode *root, int level, vector<int> &ans)
{
  if (root == nullptr)
  {
    return;
  }
  if (level == ans.size())
  {
    ans.push_back(root->data);
  }
  leftSideViewHelper(root->left, level + 1, ans);
  leftSideViewHelper(root->right, level + 1, ans);
}

vector<int> leftSideView(TreeNode *root)
{
  // your code goes here
  vector<int> ans;
  leftSideViewHelper(root, 0, ans);
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = leftSideView(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}