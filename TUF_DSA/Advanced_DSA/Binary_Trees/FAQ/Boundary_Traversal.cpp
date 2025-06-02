#include "BinaryTree.h"

bool isLeaf(TreeNode *root)
{
  return !root->left && !root->right;
}

void addLeftBoundary(TreeNode *root, vector<int> &res)
{
  TreeNode *curr = root->left;
  while (curr != nullptr)
  {
    if (!isLeaf(curr))
      res.push_back(curr->data);
    if (curr->left != nullptr)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }
}

void addLeaves(TreeNode *root, vector<int> &res)
{
  if (isLeaf(root))
  {
    res.push_back(root->data);
  }
  if (root->left)
    addLeaves(root->left, res);
  if (root->right)
    addLeaves(root->right, res);
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
  TreeNode *curr = root->right;
  vector<int> temp;
  while (curr != nullptr)
  {
    if (!isLeaf(curr))
      temp.push_back(curr->data);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  for (int i = temp.size() - 1; i >= 0; i--)
  {
    res.push_back(temp[i]);
  }
}

vector<int> boundary(TreeNode *root)
{
  // your code goes here
  vector<int> res;
  if (root == nullptr)
  {
    return res;
  }
  if (!isLeaf(root))
    res.push_back(root->data);
  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);
  return res;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = boundary(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}