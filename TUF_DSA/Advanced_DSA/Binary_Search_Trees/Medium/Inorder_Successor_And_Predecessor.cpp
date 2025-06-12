#include "BinaryTree.h"

void inOrder(TreeNode *root, vector<int> &inorder)
{
  if (root == nullptr)
  {
    return;
  }
  inOrder(root->left, inorder);
  inorder.push_back(root->data);
  inOrder(root->right, inorder);
}

vector<int> succPredBSTBrute(TreeNode *root, int key)
{
  // your code goes here
  vector<int> inorder;
  inOrder(root, inorder);
  int successor = -1;
  int predecessor = -1;
  for (int i = 0; i < inorder.size(); i++)
  {
    if (inorder[i] < key)
    {
      predecessor = inorder[i];
    }
    else if (inorder[i] > key)
    {
      successor = inorder[i];
      break;
    }
  }
  return {predecessor, successor};
}

int successor(TreeNode *root, int key)
{
  int succ = -1;
  while (root != nullptr)
  {
    if (root->data <= key)
    {
      root = root->right;
    }
    else if (root->data > key)
    {
      succ = root->data;
      root = root->left;
    }
  }
  return succ;
}

int predessor(TreeNode *root, int key)
{
  int pred = -1;
  while (root != nullptr)
  {
    if (root->data < key)
    {
      pred = root->data;
      root = root->right;
    }
    else if (root->data >= key)
    {
      root = root->left;
    }
  }
  return pred;
}

vector<int> succPredBST(TreeNode *root, int key)
{
  // your code goes here
  int pred = predessor(root, key);
  int succ = successor(root, key);
  return {pred, succ};
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter key value :" << endl;
  int key;
  cin >> key;
  vector<int> ans = succPredBST(root, key);
  cout << ans[0] << " " << ans[1] << endl;
  delete root;
}