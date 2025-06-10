#include "BinaryTree.h"

int minVal(TreeNode *root)
{
  if (root == nullptr)
  {
    return INT_MAX;
  }
  return min(root->data, min(minVal(root->left), minVal(root->right)));
}

TreeNode *remove(TreeNode *root, int val)
{
  if (root == nullptr)
  {
    return nullptr;
  }
  if (root->data > val)
  {
    root->left = remove(root->left, val);
  }
  else if (root->data < val)
  {
    root->right = remove(root->right, val);
  }
  else
  {
    if (root->left == nullptr && root->right == nullptr)
    {
      delete root;
      return nullptr;
    }
    else if (root->left == nullptr)
    {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr)
    {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      int rightMinVal = minVal(root->right);
      root->data = rightMinVal;
      root->right = remove(root->right, rightMinVal);
      return root;
    }
  }
}

// --------- Second Solution Starting -----------
TreeNode *findLeftLastRight(TreeNode *root)
{
  if (root->right == nullptr)
  {
    return root;
  }
  return findLeftLastRight(root->right);
}

TreeNode *helper(TreeNode *root)
{
  if (root->left == nullptr)
  {
    return root->right;
  }
  if (root->right == nullptr)
  {
    return root->left;
  }
  TreeNode *rootRight = root->right;
  TreeNode *leftLastRight = findLeftLastRight(root->left);
  leftLastRight->right = rootRight;
  return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == nullptr)
  {
    return nullptr;
  }
  if (root->data == key)
  {
    return helper(root);
  }
  TreeNode *temp = root;
  while (temp != nullptr)
  {
    if (temp->data > key)
    {
      if (temp->left != nullptr && temp->left->data == key)
      {
        temp->left = helper(temp->left);
        break;
      }
      else
      {
        temp = temp->left;
      }
    }
    else
    {
      if (temp->right != nullptr && temp->right->data == key)
      {
        temp->right = helper(temp->right);
        break;
      }
      else
      {
        temp = temp->right;
      }
    }
  }
  return root;
}

// ----- Second Solution End ------

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Enter value " << endl;
  int val;
  cin >> val;
  root = deleteNode(root, val);
  root->print(root);
  delete root;
}