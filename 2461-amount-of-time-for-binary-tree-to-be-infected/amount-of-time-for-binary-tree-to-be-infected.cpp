/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void give(TreeNode* r, vector<vector<int>>& a) {
    if (r == NULL) return;
    if (r->left) {
        a[r->val].push_back(r->left->val);
        a[r->left->val].push_back(r->val);
        give(r->left, a);
    }
    if (r->right) {
        a[r->val].push_back(r->right->val);
        a[r->right->val].push_back(r->val);
        give(r->right, a);
    }
  }

  int amountOfTime(TreeNode* r, int s) {
    vector<vector<int>> a(100001);
    int c = -1;
    give(r, a);
    queue<int> q;
    q.push(s);
    vector<int> vis(100001, 0);
    vis[s] = 1;

    while (!q.empty()) {
      int size = q.size();
      c++;
      for (int i = 0; i < size; i++) {
        int node = q.front();
        q.pop();
        for (int neighbor : a[node]) {
          if (!vis[neighbor]) {
            q.push(neighbor);
            vis[neighbor] = 1;
          }
        }
      }
    }
    return c;
  }
};
