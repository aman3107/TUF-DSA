#include "BinaryTree.h"

int findMinTime(unordered_map<TreeNode *, TreeNode *> parent, TreeNode *target)
{
  queue<TreeNode *> q;
  unordered_map<TreeNode *, bool> vis;
  q.push(target);
  vis[target] = true;
  int time = 0;
  while (!q.empty())
  {
    bool burn = false;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *current = q.front();
      q.pop();
      if (current->left && !vis[current->left])
      {
        q.push(current->left);
        vis[current->left] = true;
        burn = true;
      }
      if (current->right && !vis[current->right])
      {
        q.push(current->right);
        vis[current->right] = true;
        burn = true;
      }
      if (parent[current] && !vis[parent[current]])
      {
        q.push(parent[current]);
        vis[parent[current]] = true;
        burn = true;
      }
    }
    if (burn == true)
    {
      time++;
    }
  }
  return time;
}

TreeNode *markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int start)
{
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *res = new TreeNode(-1);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    if (node->data == start)
    {
      res = node;
    }
    if (node->left != nullptr)
    {
      q.push(node->left);
      parent[node->left] = node;
    }
    if (node->right != nullptr)
    {
      q.push(node->right);
      parent[node->right] = node;
    }
  }
  return res;
}

int timeToBurnTree(TreeNode *root, int start)
{
  // your code goes here
  if (root == nullptr)
  {
    return 0;
  }
  unordered_map<TreeNode *, TreeNode *> parent;
  TreeNode *target = markParent(root, parent, start);
  return findMinTime(parent, target);
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Target node" << endl;
  int start;
  cin >> start;
  int ans = timeToBurnTree(root, start);
  cout << ans << ends;
  delete root;
}
