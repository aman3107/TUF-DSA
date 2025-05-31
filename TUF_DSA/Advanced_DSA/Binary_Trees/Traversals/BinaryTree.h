#include <bits/stdc++.h>
using namespace std;

class BTreeNode
{

public:
  int data;
  BTreeNode *left;
  BTreeNode *right;

  BTreeNode(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  ~BTreeNode()
  {
    delete left;
    delete right;
  }

  BTreeNode *takeInputLevelWise()
  {
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
      return nullptr;
    }
    BTreeNode *root = new BTreeNode(rootData);
    queue<BTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      BTreeNode *front = q.front();
      q.pop();
      int leftChildData;
      cout << "Enter left child of :" << front->data << " " << endl;
      cin >> leftChildData;
      if (leftChildData != -1)
      {
        BTreeNode *leftChild = new BTreeNode(leftChildData);
        front->left = leftChild;
        q.push(leftChild);
      }
      int rightChildData;
      cout << "Enter right child of :" << front->data << " " << endl;
      cin >> rightChildData;
      if (rightChildData != -1)
      {
        BTreeNode *rightChild = new BTreeNode(rightChildData);
        front->right = rightChild;
        q.push(rightChild);
      }
    }
    return root;
  }
  void print(BTreeNode *root)
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