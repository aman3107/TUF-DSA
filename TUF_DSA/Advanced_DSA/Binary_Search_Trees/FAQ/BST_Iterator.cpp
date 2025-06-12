#include "BinaryTree.h"

// ------- Brute Start --------

class BSTIteratorBrute
{
private:
  vector<int> values;
  int ind;

  void inOrder(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    inOrder(root->left);
    values.push_back(root->data);
    inOrder(root->right);
  }

public:
  BSTIteratorBrute(TreeNode *root)
  {
    inOrder(root);
    ind = -1;
  }

  bool hasNext()
  {
    return ind + 1 < values.size();
  }

  int next()
  {
    return values[++ind];
  }
};

// -------- Brute End ---------

class BSTIterator
{
  stack<TreeNode *> st;
  stack<TreeNode *> st1;

  void pushAllLeft(TreeNode *root)
  {
    while (root != nullptr)
    {
      st.push(root);
      root = root->left;
    }
  }

  void pushAllRight(TreeNode *root)
  {
    while (root != nullptr)
    {
      st1.push(root);
      root = root->right;
    }
  }

public:
  BSTIterator(TreeNode *root)
  {
    pushAllLeft(root);
  }

  bool hasNext()
  {
    return !st.empty();
  }

  int next()
  {
    TreeNode *node = st.top();
    st.pop();
    pushAllLeft(node->right);
    return node->data;
  }
};

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  BSTIterator *it = new BSTIterator(root);
  while (it->hasNext())
  {
    cout << it->next() << endl;
  }
  delete root;
}