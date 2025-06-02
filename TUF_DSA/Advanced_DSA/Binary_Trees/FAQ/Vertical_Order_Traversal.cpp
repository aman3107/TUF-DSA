#include "BinaryTree.h"

vector<vector<int>> verticalTraversal(TreeNode *root)
{
  // your code goes here

  vector<vector<int>> result;
  if (root == nullptr)
  {
    return result;
  }
  queue<pair<TreeNode *, pair<int, int>>> q;
  map<int, map<int, multiset<int>>> mp;
  q.push({root, {0, 0}});
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    TreeNode *node = p.first;
    int x = p.second.first;
    int y = p.second.second;
    mp[x][y].insert(node->data);
    if (node->left)
    {
      q.push({node->left, {x - 1, y + 1}});
    }
    if (node->right)
    {
      q.push({node->right, {x + 1, y + 1}});
    }
  }
  for (auto &it1 : mp)
  {
    vector<int> temp;
    for (auto &it2 : it1.second)
    {
      for (auto &it3 : it2.second)
      {

        temp.push_back(it3);
      }
    }
    result.push_back(temp);
  }
  return result;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<vector<int>> ans = verticalTraversal(root);
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