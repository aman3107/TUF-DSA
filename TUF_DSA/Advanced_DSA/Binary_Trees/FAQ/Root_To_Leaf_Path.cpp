#include "BinaryTree.h"

void allRootToLeafHelper(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp)
{
  if (root == nullptr)
  {
    return;
  }
  temp.push_back(root->data);
  if (root->left == nullptr && root->right == nullptr)
  {
    ans.push_back(temp);
  }

  allRootToLeafHelper(root->left, ans, temp);
  allRootToLeafHelper(root->right, ans, temp);
  temp.pop_back();
}

vector<vector<int>> allRootToLeaf(TreeNode *root)
{
  // your code goes here
  vector<vector<int>> ans;
  if (root == nullptr)
  {
    return ans;
  }
  vector<int> temp;
  allRootToLeafHelper(root, ans, temp);
  return ans;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  vector<vector<int>> ans = allRootToLeaf(root);
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