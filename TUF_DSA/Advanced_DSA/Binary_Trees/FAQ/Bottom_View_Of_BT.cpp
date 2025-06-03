#include "BinaryTree.h"

vector<int> bottomView(TreeNode *root)
{
  // your code goes here
  vector<int> ans;
  if (root == nullptr)
  {
    return ans;
  }
  queue<pair<TreeNode *, int>> q;
  map<int, int> mp;
  q.push({root, 0});
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    TreeNode *node = p.first;
    int line = p.second;
    mp[line] = node->data;
    if (node->left != nullptr)
    {
      q.push({node->left, line - 1});
    }
    if (node->right != nullptr)
    {
      q.push({node->right, line + 1});
    }
  }
  for (auto it : mp)
  {
    ans.push_back(it.second);
  }
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = bottomView(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}
