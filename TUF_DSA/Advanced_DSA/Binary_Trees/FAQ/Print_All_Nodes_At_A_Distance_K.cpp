#include "BinaryTree.h"

void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
{
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();
    if (current->left)
    {
      parent_track[current->left] = current;
      q.push(current->left);
    }
    if (current->right)
    {
      parent_track[current->right] = current;
      q.push(current->right);
    }
  }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  // your code goes here
  unordered_map<TreeNode *, TreeNode *> parent_track;
  markParents(root, parent_track);
  queue<TreeNode *> q;
  q.push(target);
  unordered_map<TreeNode *, bool> vis;
  vis[target] = true;
  int dis = 0;
  while (!q.empty())
  {
    int size = q.size();
    if (dis++ == k)
      break;
    for (int i = 0; i < size; i++)
    {
      TreeNode *current = q.front();
      q.pop();
      if (current->left && !vis[current->left])
      {
        vis[current->left] = true;
        q.push(current->left);
      }
      if (current->right && !vis[current->right])
      {
        vis[current->right] = true;
        q.push(current->right);
      }
      if (parent_track[current] && !vis[parent_track[current]])
      {
        vis[parent_track[current]] = true;
        q.push(parent_track[current]);
      }
    }
  }
  vector<int> res;
  while (!q.empty())
  {
    TreeNode *current = q.front();
    res.push_back(current->data);
    q.pop();
  }
  return res;
}

int main()
{
  TreeNode *root = root->takeInputLevelWise();
  cout << "Target Node " << endl;
  int tar;
  cin >> tar;
  TreeNode *target = new TreeNode(tar);
  int k;
  cin >> k;
  vector<int> ans = distanceK(root, target, k);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete root;
}