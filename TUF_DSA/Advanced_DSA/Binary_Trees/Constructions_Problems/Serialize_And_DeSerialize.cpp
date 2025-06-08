#include "BinaryTree.h"

string serialize(TreeNode *root)
{
  if (root == nullptr)
  {
    return "";
  }
  string res = "";
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    if (node == nullptr)
    {
      res += "#,";
    }
    else
    {
      res += to_string(node->data) + ',';
    }
    if (node != nullptr)
    {
      q.push(node->left);
      q.push(node->right);
    }
  }
  return res;
}

TreeNode *deserialize(string data)
{
  if (data.size() == 0)
  {
    return nullptr;
  }
  stringstream s(data);
  string str;
  getline(s, str, ',');
  queue<TreeNode *> q;
  TreeNode *root = new TreeNode(stoi(str));
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    getline(s, str, ',');
    if (str == "#")
    {
      node->left = nullptr;
    }
    else
    {
      TreeNode *leftNode = new TreeNode(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }
    getline(s, str, ',');
    if (str == "#")
    {
      node->right = nullptr;
    }
    else
    {
      TreeNode *rightNode = new TreeNode(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  string res = serialize(root);
  TreeNode *ans = deserialize(res);
  ans->print(ans);
  delete root;
  delete ans;
}
