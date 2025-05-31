#include "BinaryTree.h"

vector<int> preOrderIterative(BTreeNode *root)
{
  vector<int> ans;
  if (root == nullptr)
  {
    return ans;
  }
  stack<BTreeNode *> st;
  st.push(root);
  BTreeNode *node;
  while (!st.empty())
  {
    node = st.top();
    st.pop();
    ans.push_back(node->data);
    if (node->right != nullptr)
    {
      st.push(node->right);
    }
    if (node->left != nullptr)
    {
      st.push(node->left);
    }
  }
  return ans;
}

void preOrderHelper(BTreeNode *root, vector<int> &ans)
{
  if (root == nullptr)
  {
    return;
  }
  ans.push_back(root->data);
  preOrderHelper(root->left, ans);
  preOrderHelper(root->right, ans);
}

vector<int> preOrder(BTreeNode *root)
{
  vector<int> ans;
  preOrderHelper(root, ans);
  return ans;
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  vector<int> ans = preOrderIterative(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << "  ";
  }
  cout << endl;
}