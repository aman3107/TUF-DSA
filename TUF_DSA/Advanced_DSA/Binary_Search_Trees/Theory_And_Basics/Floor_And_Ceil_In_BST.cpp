#include "BinaryTree.h"

int floorVal(TreeNode *root, int key)
{
  int floor = -1;
  while (root)
  {
    if (root->data == key)
    {
      floor = root->data;
      return floor;
    }
    if (root->data < key)
    {
      floor = root->data;
      root = root->right;
    }
    else
    {
      root = root->left;
    }
  }
  return floor;
}

int ceilVal(TreeNode *root, int key)
{
  int ceil = -1;
  while (root)
  {
    if (root->data == key)
    {
      return root->data;
    }
    if (root->data > key)
    {
      ceil = root->data;
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  return ceil;
}

vector<int> floorCeilOfBST(TreeNode *root, int key)
{
  // your code goes here
  int floor = floorVal(root, key);
  int ceil = ceilVal(root, key);
  return {floor, ceil};
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter key value " << endl;
  int key;
  cin >> key;
  vector<int> ans = floorCeilOfBST(root, key);
  cout << ans[0] << " " << ans[1] << endl;
}