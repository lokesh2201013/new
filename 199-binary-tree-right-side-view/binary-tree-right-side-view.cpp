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
    vector<int> rightSideView(TreeNode* r) {
        vector<int> a;
        if (!r) return a; // Check if the root is null

        queue<pair<TreeNode*, int>> q;
        map<int, int> m;
        q.push({r, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int l = it.second;
            m[abs(l)] = node->val;

            if (node->left) q.push({node->left, l + 1});
            if (node->right) q.push({node->right, l + 1});
        }
        for (auto it : m) {
            a.push_back(it.second);
        }

        return a;
    }
};
