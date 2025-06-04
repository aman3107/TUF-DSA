#include "BinaryTree.h"

bool rootToNodePathHelper(TreeNode *root, int x, vector<int> &ans)
{
  if (root == nullptr)
  {
    return false;
  }
  ans.push_back(root->data);
  if (root->data == x)
  {
    return true;
  }
  if (rootToNodePathHelper(root->left, x, ans) || rootToNodePathHelper(root->right, x, ans))
  {
    return true;
  }
  ans.pop_back();
  return false;
}

vector<int> rootToNodePath(TreeNode *root, int x)
{
  vector<int> ans;
  if (root == nullptr)
  {
    return ans;
  }
  rootToNodePathHelper(root, x, ans);
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  int x;
  cout << "Enter value of x " << endl;
  cin >> x;
  vector<int> ans = rootToNodePath(root, x);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}