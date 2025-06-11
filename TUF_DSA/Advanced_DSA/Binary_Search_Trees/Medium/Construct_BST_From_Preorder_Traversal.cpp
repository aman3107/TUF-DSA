#include "BinaryTree.h"

TreeNode *bstFromPreorderBrute(vector<int> &preorder)
{
  // your code goes here
  if (preorder.size() == 0)
  {
    return nullptr;
  }
  TreeNode *root = new TreeNode(preorder[0]);
  stack<TreeNode *> st;
  st.push(root);
  for (int i = 1; i < preorder.size(); i++)
  {
    TreeNode *node = st.top();
    TreeNode *child = new TreeNode(preorder[i]);
    while (!st.empty() && st.top()->data < child->data)
    {
      node = st.top();
      st.pop();
    }
    if (node->data < child->data)
    {
      node->right = child;
    }
    else
    {
      node->left = child;
    }
    st.push(child);
  }
  return root;
}

TreeNode *helper(vector<int> &preorder, int &i, int bound)
{
  if (i == preorder.size() || preorder[i] > bound)
  {
    return nullptr;
  }
  TreeNode *root = new TreeNode(preorder[i]);
  i++;
  root->left = helper(preorder, i, root->data);
  root->right = helper(preorder, i, bound);
  return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
  // your code goes here
  int i = 0;
  return helper(preorder, i, INT_MAX);
}

int main()
{
  int n;
  cin >> n;
  vector<int> preorder;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    preorder.push_back(data);
  }
  TreeNode *root = bstFromPreorder(preorder);
  root->print(root);
  delete root;
}