#include "BinaryTree.h"

vector<int> zigZagTraversal(TreeNode *root)
{
  // Code here
  vector<int> zigZag;
  if (root == nullptr)
  {
    return zigZag;
  }
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *node;
  bool leftToRight = true;
  while (!q.empty())
  {
    int size = q.size();
    vector<int> temp(size);
    for (int i = 0; i < size; i++)
    {
      node = q.front();
      q.pop();
      int ind = leftToRight ? i : (size - 1 - i);
      temp[ind] = node->data;
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    for (int j = 0; j < temp.size(); j++)
    {
      zigZag.push_back(temp[j]);
    }
    leftToRight = !leftToRight;
  }
  return zigZag;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  // your code goes here
  vector<vector<int>> ans;
  if (root == nullptr)
  {
    return ans;
  }
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *node;
  bool leftToRight = true;
  while (!q.empty())
  {
    int size = q.size();
    vector<int> temp(size);
    for (int i = 0; i < size; i++)
    {
      node = q.front();
      q.pop();
      int ind = leftToRight ? i : (size - 1 - i);
      temp[ind] = node->data;
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    ans.push_back(temp);
    leftToRight = !leftToRight;
  }
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<vector<int>> ans = zigzagLevelOrder(root);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); i++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  delete root;
}