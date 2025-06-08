#include "BinaryTree.h"

TreeNode *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inMap)
{
  // your code goes here
  if (inStart > inEnd || postStart > postEnd)
  {
    return nullptr;
  }

  TreeNode *root = new TreeNode(postorder[postEnd]);
  int rootIndex = inMap[root->data];
  int numsLeft = rootIndex - inStart;
  root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
  root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  // your code goes here
  int n = inorder.size();
  unordered_map<int, int> inMap;
  for (int i = 0; i < n; i++)
  {
    inMap[inorder[i]] = i;
  }
  TreeNode *root = buildTreeHelper(inorder, 0, n - 1, postorder, 0, n - 1, inMap);
  return root;
}

int main()
{
  int n;
  cin >> n;
  vector<int> inOrder;
  vector<int> postOrder;
  cout << "enter inorder " << endl;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    inOrder.push_back(data);
  }
  cout << "enter postorder " << endl;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    postOrder.push_back(data);
  }
  TreeNode *root = buildTree(inOrder, postOrder);
  root->print(root);
  delete root;
}