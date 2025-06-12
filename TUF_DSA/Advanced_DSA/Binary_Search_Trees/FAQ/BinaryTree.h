#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  ~TreeNode()
  {
    delete left;
    delete right;
  }

  TreeNode *takeInputLevelWise()
  {
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
      return nullptr;
    }
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();
      int leftChildData;
      cout << "Enter left child of :" << front->data << " " << endl;
      cin >> leftChildData;
      if (leftChildData != -1)
      {
        TreeNode *leftChild = new TreeNode(leftChildData);
        front->left = leftChild;
        q.push(leftChild);
      }
      int rightChildData;
      cout << "Enter right child of :" << front->data << " " << endl;
      cin >> rightChildData;
      if (rightChildData != -1)
      {
        TreeNode *rightChild = new TreeNode(rightChildData);
        front->right = rightChild;
        q.push(rightChild);
      }
    }
    return root;
  }
  void print(TreeNode *root)
  {
    if (root == NULL)
      return;
    cout << root->data << ":";
    if (root->left != NULL)
    {
      cout << "L " << root->left->data << ", ";
    }
    if (root->right != NULL)
    {
      cout << "R " << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
  }
};