#include "BinaryTree.h"

int widthOfBinaryTree(TreeNode *root)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  int maxWidth = 0;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty())
  {
    int n = q.size();
    int mmin = q.front().second;
    int first = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
      int curr_id = q.front().second - mmin;
      TreeNode *node = q.front().first;
      q.pop();

      if (i == 0)
        first = curr_id;
      if (i == n - 1)
        last = curr_id;
      if (node->left)
      {
        q.push({node->left, curr_id * 2 + 1});
      }
      if (node->right)
      {
        q.push({node->right, curr_id * 2 + 2});
      }
    }
    maxWidth = max(maxWidth, (last - first + 1));
  }
  return maxWidth;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << widthOfBinaryTree(root) << endl;
  delete root;
}