#include "BinaryTree.h"

// --------- Brute Start ------------

void inorder(TreeNode *root, vector<int> &arr)
{
  if (root == nullptr)
  {
    return;
  }
  inorder(root->left, arr);
  arr.push_back(root->data);
  inorder(root->right, arr);
}

void inOrder(TreeNode *root, vector<int> &arr, int &ind)
{
  if (root == nullptr)
  {
    return;
  }
  inOrder(root->left, arr, ind);
  root->data = arr[ind++];
  inOrder(root->right, arr, ind);
}

void recoverTreeBrute(TreeNode *root)
{
  // your code goes here
  vector<int> arr;
  inorder(root, arr);
  sort(arr.begin(), arr.end());
  int ind = 0;
  inOrder(root, arr, ind);
}

//  --------- Brute End -----------

void helper(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&middle, TreeNode *&last)
{
  if (root == nullptr)
  {
    return;
  }
  helper(root->left, prev, first, middle, last);
  if (prev != nullptr && (root->data < prev->data))
  {
    if (first == nullptr)
    {
      first = prev;
      middle = root;
    }
    else
    {
      last = root;
    }
  }
  prev = root;
  helper(root->right, prev, first, middle, last);
}

void recoverTree(TreeNode *root)
{
  // your code goes here
  TreeNode *prev = nullptr;
  TreeNode *first = nullptr;
  TreeNode *middle = nullptr;
  TreeNode *last = nullptr;
  helper(root, prev, first, middle, last);
  if (last != nullptr && first != nullptr)
  {
    int c = first->data;
    first->data = last->data;
    last->data = c;
  }
  else if (first != nullptr && middle != nullptr)
  {
    int c = first->data;
    first->data = middle->data;
    middle->data = c;
  }
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  recoverTree(root);
  root->print(root);
  delete root;
}