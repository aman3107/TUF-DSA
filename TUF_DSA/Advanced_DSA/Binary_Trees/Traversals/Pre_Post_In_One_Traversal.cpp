#include "BinaryTree.h"
vector<vector<int>> treeTraversal(BTreeNode *root)
{
  // your code goes here
  vector<int> pre, in, post;
  if (root == nullptr)
  {
    return {in, pre, post};
  }
  stack<pair<BTreeNode *, int>> st;
  BTreeNode *node;
  st.push({root, 1});
  while (!st.empty())
  {
    node = st.top().first;
    int state = st.top().second;
    st.pop();
    if (state == 1)
    {
      pre.push_back(node->data);
      st.push({node, 2});
      if (node->left != nullptr)
      {
        st.push({node->left, 1});
      }
    }
    else if (state == 2)
    {
      in.push_back(node->data);
      st.push({node, 3});
      if (node->right != nullptr)
      {
        st.push({node->right, 1});
      }
    }
    else
    {
      post.push_back(node->data);
    }
  }
  return {in, pre, post};
}

int main()
{

  BTreeNode *root = root->takeInputLevelWise();
  vector<vector<int>> ans = treeTraversal(root);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}