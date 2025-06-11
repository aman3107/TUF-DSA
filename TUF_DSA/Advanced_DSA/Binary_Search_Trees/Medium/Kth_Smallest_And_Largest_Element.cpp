#include "BinaryTree.h"

// ------ Brute Force Start -------

void inorderBrute(TreeNode *root, vector<int> &arr)
{
  if (root == nullptr)
  {
    return;
  }
  inorderBrute(root->left, arr);
  arr.push_back(root->data);
  inorderBrute(root->right, arr);
}

vector<int> kLargesSmallBrute(TreeNode *root, int k)
{
  // your code goes here
  vector<int> arr;
  inorderBrute(root, arr);
  int n = arr.size();
  return {arr[k - 1], arr[n - k]};
}

// ------ Brute Force End -------

// ----- Optimal Start ------

void inorder(TreeNode *root, int &k, int &kthSmallest)
{
  if (root == nullptr)
  {
    return;
  }
  inorder(root->left, k, kthSmallest);
  if (--k == 0)
  {
    kthSmallest = root->data;
    return;
  }
  inorder(root->right, k, kthSmallest);
}

void reverse_inorder(TreeNode *root, int &k, int &kthLargest)
{
  if (root == nullptr)
  {
    return;
  }
  reverse_inorder(root->right, k, kthLargest);
  if (--k == 0)
  {
    kthLargest = root->data;
    return;
  }
  reverse_inorder(root->left, k, kthLargest);
}

vector<int> kLargesSmall(TreeNode *root, int k)
{
  // your code goes here
  int kthSmallest = -1;
  int kthLargest = -1;
  int n_k = k;
  inorder(root, k, kthSmallest);
  reverse_inorder(root, n_k, kthLargest);
  return {kthSmallest, kthLargest};
}

// -------- Optimal End ---------

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter k value :" << endl;
  int k;
  cin >> k;

  vector<int> ans = kLargesSmall(root, k);
  cout << ans[0] << " " << ans[1] << endl;
  delete root;
}