#include "BinaryTree.h"

int maxPathSumHelper(BTreeNode *root, int &maxSum)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
  int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
  maxSum = max(maxSum, leftSum + rightSum + root->data);
  return root->data + max(leftSum, rightSum);
}

int maxPathSum(BTreeNode *root)
{
  // your code goes here
  int maxSum = INT_MIN;
  maxPathSumHelper(root, maxSum);
  return maxSum;
}

int main()
{
  BTreeNode *root = root->takeInputLevelWise();
  cout << maxPathSum(root) << endl;
  delete root;
}