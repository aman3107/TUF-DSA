#include "BinaryTree.h"

vector<int> floorAndceildata(TreeNode *root, int key)
{
  int floor = -1;
  int ceil = -1;
  while (root)
  {
    if (root->data == key)
    {
      floor = root->data;
      ceil = root->data;
      break;
    }
    if (root->data < key)
    {
      floor = root->data;
      root = root->right;
    }
    else
    {
      ceil = root->data;
      root = root->left;
    }
  }
  return {floor, ceil};
}

int floordata(TreeNode *root, int key)
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

int ceildata(TreeNode *root, int key)
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
  int floor = floordata(root, key);
  int ceil = ceildata(root, key);
  return {floor, ceil};
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter key dataue " << endl;
  int key;
  cin >> key;
  vector<int> ans = floorCeilOfBST(root, key);
  cout << ans[0] << " " << ans[1] << endl;
}