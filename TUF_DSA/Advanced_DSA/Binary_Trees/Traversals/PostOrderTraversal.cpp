#include "BinaryTree.h"

vector<int> postOrderIterative(BTreeNode *root)
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
    if (node->left != nullptr)
    {
      st.push(node->left);
    }
    if (node->right != nullptr)
    {
      st.push(node->right);
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

void postOrderHelper(BTreeNode *root, vector<int> &ans)
{
  if (root == nullptr)
  {
    return;
  }
  postOrderHelper(root->left, ans);
  postOrderHelper(root->right, ans);
  ans.push_back(root->data);
}

vector<int> postOrder(BTreeNode *root)
{
  vector<int> ans;
  postOrderHelper(root, ans);
  return ans;
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  vector<int> ans = postOrderIterative(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}