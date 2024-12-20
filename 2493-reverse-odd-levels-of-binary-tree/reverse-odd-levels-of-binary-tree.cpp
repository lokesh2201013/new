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
    vector<vector<int>> bfs(TreeNode* r) {
        vector<vector<int>> re;
        if (!r) return re;
        
        queue<TreeNode*> q;
        q.push(r);
        while (!q.empty()) {
            int s = q.size();
            vector<int> cl;
            for (int i = 0; i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                cl.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            re.push_back(cl);
        }
        return re;
    }

    TreeNode* buildTreeFromLevels(const vector<vector<int>>& re) {
        if (re.empty()) return nullptr;

      
        TreeNode* root = new TreeNode(re[0][0]);
        queue<TreeNode*> q;
        q.push(root);

        int level = 1; 
        while (!q.empty() && level < re.size()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (2 * i < re[level].size()) {
                    curr->left = new TreeNode(re[level][2 * i]);
                    q.push(curr->left);
                }

                if (2 * i + 1 < re[level].size()) {
                    curr->right = new TreeNode(re[level][2 * i + 1]);
                    q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* r) {
        vector<vector<int>> re = bfs(r);

        for (int i = 0; i < re.size(); i++) {
            if (i % 2 != 0) reverse(re[i].begin(), re[i].end());
        }
        return buildTreeFromLevels(re);
    }
};
