#include "BinaryTree.h"

vector<int> topView(TreeNode *root)
{
  // your code goes here
  vector<int> res;
  if (root == nullptr)
  {
    return res;
  }
  map<int, int> mp;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    TreeNode *node = p.first;
    int x = p.second;
    if (mp.find(x) == mp.end())
    {
      mp[x] = node->data;
    }
    if (node->left)
    {
      q.push({node->left, x - 1});
    }
    if (node->right)
    {
      q.push({node->right, x + 1});
    }
  }
  for (auto it : mp)
  {
    res.push_back(it.second);
  }
  return res;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<int> ans = topView(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}