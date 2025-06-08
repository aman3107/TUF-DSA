#include "BinaryTree.h"

TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
  if (inStart > inEnd || preStart > preEnd)
  {
    return nullptr;
  }
  TreeNode *root = new TreeNode(preorder[preStart]);
  int rootIndex = inMap[root->data];
  int numsLeft = rootIndex - inStart;

  root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, rootIndex - 1, inMap);
  root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, rootIndex + 1, inEnd, inMap);
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  // your code goes here
  int n = inorder.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[inorder[i]] = i;
  }

  TreeNode *root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
  return root;
}

int main()
{
  int n;
  cin >> n;
  vector<int> inOrder;
  vector<int> preOrder;
  cout << "enter inorder " << endl;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    inOrder.push_back(data);
  }
  cout << "enter preorder " << endl;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    preOrder.push_back(data);
  }
  TreeNode *root = buildTree(preOrder, inOrder);
  root->print(root);
  delete root;
}