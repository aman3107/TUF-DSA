#include "BinaryTree.h"

vector<vector<int>> levelOrder(BTreeNode *root)
{
  vector<vector<int>> ans;
  if (root == nullptr)
  {
    return ans;
  }
  queue<BTreeNode *> q;
  q.push(root);
  BTreeNode *node;
  while (!q.empty())
  {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      node = q.front();
      q.pop();
      level.push_back(node->data);
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    ans.push_back(level);
  }
  return ans;
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  vector<vector<int>> ans = levelOrder(root);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  delete root;
}