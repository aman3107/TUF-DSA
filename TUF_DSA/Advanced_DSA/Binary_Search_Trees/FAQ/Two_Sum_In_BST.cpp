#include "BinaryTree.h"

// --------- Brute Start ------------

void inOrder(TreeNode *root, vector<int> &arr)
{
  if (root == nullptr)
  {
    return;
  }

  inOrder(root->left, arr);
  arr.push_back(root->data);
  inOrder(root->right, arr);
}

bool twoSumBSTBrute(TreeNode *root, int k)
{
  // your code goes here
  vector<int> arr;
  inOrder(root, arr);
  int i = 0;
  int j = arr.size();

  while (i < j)
  {
    if (arr[i] + arr[j] == k)
    {
      return true;
    }
    else if (arr[i] + arr[j] > k)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  return false;
}

// ------- Brute End --------//

class BSTIterator
{
  stack<TreeNode *> st;
  // reverse == true -> before
  // reverse == false ->next
  bool reverse = true;

  void pushAll(TreeNode *root)
  {
    while (root != nullptr)
    {
      st.push(root);
      if (reverse == false)
      {
        root = root->left;
      }
      else
      {
        root = root->right;
      }
    }
  }

public:
  BSTIterator(TreeNode *root, bool isReverse)
  {
    reverse = isReverse;
    pushAll(root);
  }

  bool hasNext()
  {
    return !st.empty();
  }

  int next()
  {
    TreeNode *node = st.top();
    st.pop();
    if (reverse == false)
    {
      pushAll(node->right);
    }
    else
    {
      pushAll(node->left);
    }

    return node->data;
  }
};

bool twoSumBST(TreeNode *root, int k)
{
  // your code goes here
  BSTIterator l(root, false);
  BSTIterator r(root, true);

  int i = l.next();
  int j = r.next();
  while (i < j)
  {
    if (i + j == k)
    {
      return true;
    }
    else if (i + j < k)
    {
      i = l.next();
    }
    else
    {
      j = r.next();
    }
  }

  return false;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter value of k " << endl;
  int k;
  cin >> k;
  cout << twoSumBST(root, k) << endl;
  delete root;
}