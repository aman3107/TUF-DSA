#include "BinaryTree.h"

// --------- Brute Start ----------

bool checkBST(TreeNode *root, int minVal, int maxVal)
{
  if (root == nullptr)
  {
    return true;
  }
  if (root->data >= maxVal || root->data <= minVal)
  {
    return false;
  }
  return checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
}

int countNodes(TreeNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

void helper(TreeNode *root, int &ans)
{
  if (root == nullptr)
  {
    return;
  }
  bool bst = checkBST(root, INT_MIN, INT_MAX);
  if (bst)
  {
    ans = max(ans, countNodes(root));
  }
  helper(root->left, ans);
  helper(root->right, ans);
}

int largestBSTBrute(TreeNode *root)
{
  // your code goes here
  int ans = 0;
  helper(root, ans);
  return ans;
}

// ---------- Brute End ---------------

class Node
{
public:
  int minVal;
  int maxVal;
  int size;

  Node(int size, int maxVal, int minVal)
  {
    this->size = size;
    this->maxVal = maxVal;
    this->minVal = minVal;
  }
};

Node helper(TreeNode *root)
{
  if (root == nullptr)
  {
    return Node(0, INT_MIN, INT_MAX);
  }
  Node left = helper(root->left);
  Node right = helper(root->right);

  if (left.maxVal < root->data && root->data < right.minVal)
  {
    return Node(left.size + right.size + 1, max(root->data, right.maxVal), min(root->data, left.minVal));
  }

  return Node(max(left.size, right.size), INT_MAX, INT_MIN);
}

int largestBST(TreeNode *root)
{
  // your code goes here

  return helper(root).size;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << largestBST(root) << endl;
  delete root;
}