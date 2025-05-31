#include "BinaryTree.h"

vector<int> inOrderIterative(BTreeNode *root)
{
  stack<BTreeNode *> st;
  vector<int> ans;
  BTreeNode *node = root;
  while (true)
  {
    if (node != nullptr)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (st.empty())
        break;
      else
        node = st.top();
      st.pop();
      ans.push_back(node->data);
      node = node->right;
    }
  }
  return ans;
}

void inOrder(BTreeNode *root)
{
  if (root == nullptr)
  {
    return;
  }
  inOrder(root->left);
  cout << root->data << ",";
  inOrder(root->right);
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  inOrder(root);
  vector<int> ans = inOrderIterative(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}